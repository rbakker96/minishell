/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_one.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:27:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/21 16:39:34 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print(t_data *data, int fd, char *str, char *malloced_str)
{
	int length;
	int written;

	length = ft_strlen(str);
	written = write(fd, str, length);
	if (written == -1)
		write_error(data, malloced_str);
	return ;
}

void	print_char(t_data *data, int fd, char c, char *malloced_str)
{
	int written;

	written = write(fd, &c, 1);
	if (written == -1)
		write_error(data, malloced_str);
	return ;
}

int		prompt(t_data *data)
{
	char *directory;

	print(data, 1, "\033[1;32m", 0);
	print(data, 1, "→ ", 0);
	print(data, 1, "\033[1;36m", 0);
	directory = get_current_directory(data);
	print(data, 1, directory, directory);
	free(directory);
	print(data, 1, " ",0 );
	print(data, 1, "\033[0m", 0);
	return (0);
}

char	*get_current_directory(t_data *data)
{
	char buf[PATH_MAX];
	int index;
	char *path;
	char **directory;

	path = getcwd(buf, (size_t)PATH_MAX);
	if (path == NULL)
		get_directory_error(data);
	directory = ft_split(path, '/');
	if(directory == NULL)
		malloc_error(data, 0, 0);
	index = get_array_size(directory);
	path = ft_strdup(directory[index - 1]);
	if (path == NULL)
		malloc_error(data, 0, 0);
	free_array(directory);
	return (path);
}
