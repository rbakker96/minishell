/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_one.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:27:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/25 10:35:59 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		print(int fd, char *str) //make it a void later like print char
{
	int length;
	int written;

	length = ft_strlen(str);
	written = write(fd, str, length);
//	CLEAR STRUCT WHEN FAIL
//
	if (written == -1)
		return (-1);
	return (0);
}

void	print_char(int fd, char c)
{
	int written;

	written = write(fd, &c, 1);
//	CLEAR STRUCT WHEN FAIL
//
	return ;
}

int		prompt(void)
{
	char *directory;

	directory = get_current_directory();
	print(1, "\033[1;32m");
	print(1, "→ ");
	print(1, "\033[1;36m");
	print(1, directory);
	print(1, " ");
	print(1, "\033[0m");
	free(directory);
	return (0);
}

char	*get_current_directory(void)
{
	char buf[PATH_MAX];
	int index;
	char *path;
	char **directory;

	path = getcwd(buf, (size_t)PATH_MAX);
//	CLEAR STRUCT WHEN FAIL
//
	directory = ft_split(path, '/');
//	CLEAR STRUCT WHEN FAIL
//
	index = get_array_size(directory);
	path = ft_strdup(directory[index - 1]);
//	CLEAR STRUCT WHEN FAIL
//
	free_array(directory);
	return (path);
}

void	free_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != 0)
			i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}




