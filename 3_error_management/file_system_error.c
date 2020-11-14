/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_system_error.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 10:18:54 by roybakker     #+#    #+#                 */
/*   Updated: 2020/11/02 11:21:04 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_file_permission(t_data *data, char *path)
{
	struct stat stats;

	if (stat(path, &stats) == -1)
	{
		free(data->args);
		data->args = NULL;
		print_builtin_errno(data, path, 127);
	}
	if ((stats.st_mode & S_IFDIR) == 16384)
		print_special_errno(data, path, "is a directory", 126);
	if ((stats.st_mode & S_IXUSR) == 0)
		print_special_errno(data, path, "Permission denied", 126);
}

void	print_redir_erno(t_data *data, char *filename, int exit_code)
{
	int errno;
    /*
     * Anatoliy:
     * You should avoid magic numbers in your code. Don't expect people to remember
     * what file descriptor 2 is (I personally wouldn't know off the top of my head).
     * The code thus becomes not self-explaining.
     *
     * Instead, create a const variable or a preprocessor definition in some header
     * and reuse it. In this particular case, there's already a STDERR_FILENO definition
     * in unistd.h.
     */
	print(data, 2, "minishell : ", 0);
	print(data, 2, filename, 0);
	print(data, 2, " : ", 0);
	print(data, 2, strerror(errno), 0);
	print_char(data, 2, '\n', 0);
	g_exit_code = exit_code;
}

void	print_errno(t_data *data, int cmd, char *filename, int exit_code)
{
	int errno;

	print(data, 2, "minishell : ", 0);
	print(data, 2, filename, 0);
	print(data, 2, " : ", 0);
	print(data, 2, strerror(errno), 0);
	print_char(data, 2, '\n', 0);
	if (data->commands[cmd]->pipe_nb == 0)
		g_exit_code = exit_code;
	else
	{
		clear_memory(data);
		exit(exit_code);
	}
}

void	print_builtin_errno(t_data *data, char *filename, int exit_code)
{
	int errno;

	print(data, 2, "minishell : ", 0);
	print(data, 2, filename, 0);
	print(data, 2, " : ", 0);
	print(data, 2, strerror(errno), 0);
	print_char(data, 2, '\n', 0);

	/*
	 * Anatoliy:
	 * Any resource should ideally have a single clear owner. A function that allocated/retained/acquired
	 * a resource should be responsible for its deallocation/release.
	 *
	 * What you're doing here is spreading ownership all over your code. Your main() created and initialized
	 * data, but you can't really know for sure who's destroying it.
	 *
	 * When there's no clear owner, there's no clear lifetime of a resource, many things can easily go wrong.
	 * Some functions might decide to free the object, some will rely on it to still be present etc.
	 * It's very fragile.
	 *
	 * C language unfortunately is not preventing you from shooting your feet here, so it takes some discipline
	 * to design code with ownership in mind.
	 *
	 * Also, see my comment below about exit(), it's related. The reason you need to put your cleanup routine
	 * call here is that you're not propagating errors all the way to the top.
	 */
	clear_memory(data);

	/*
	 * Anatoliy:
	 * You should ideally never use exit() or abort().
	 *
	 * Instead, your functions should indicate error conditions (most often it's done with their return
	 * values). You should then propagate those errors up the call chain all the way to main, which
	 * would exit normally (with a return statement).
	 *
	 * The reason for this is that exit() is not guaranteed to clean up all resources
	 * that you're retaining. Yes, it will free allocated memory and close files, but think
	 * about external things: temporary files on disk, data in the database etc. etc.
	 *
	 * What if you need to execute some shutdown routines (similar to your clear_memory())? Can you
	 * expect anyone working with your code to know/remember to call it before every exit()?
	 *
	 * (And yes, I know, it's much easier to fire-and-forget by calling exit, but this approach has just
	 * way to many drawbacks to be usable in commercial software)
	 */
	exit(exit_code);
}

void	get_directory_error(t_data *data)
{
	print(data, 2, "minishell : getcwd function failed\n", 0);
	clear_used_memory(data);
	exit(1);
}
