/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_one.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:27:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/22 11:56:48 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		print(char *str)
{
	int length;
	int written;

	length = ft_strlen(str);
	written = write(1, str, length);
//		CLEAR STRUCT WHEN FAIL
//
	return (0);
}

int		prompt(void)
{
	char *directory;

	directory = get_current_directory();
	print("\033[1;32m");
	print("→ ");
	print("\033[1;36m");
	print(directory);
	print(" ");
	print("\033[0m");
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




