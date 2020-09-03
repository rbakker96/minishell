/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_one.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:27:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 20:31:27 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		print(char *str)
{
	int length;
	int written;

	length = ft_strlen(str);
	written = write(1, str, length);
	if (written == -1)
		return (-1);
	return (0);
}

int		calculate_table_size(char **str)
{
	int 	size;
	int 	index;
	char	**sub_array;

	size = 0;
	index = 0;
	while (str[index] != 0)
	{
		sub_array = ft_split(str[index], '|');
		size += commands_count(sub_array);
		free(sub_array);
		index++;
	}
	return (size);
}

int		commands_count(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

