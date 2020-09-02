/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_one.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:27:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/02 15:53:47 by roybakker     ########   odam.nl         */
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

int		redirection_pipe_check(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '<' || str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

int		commands_count(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int		arguments_count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i] != '\0')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}
