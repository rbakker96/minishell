/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_command.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 14:19:16 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/15 15:21:27 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_empty_command(char **line, int i, int x)
{
	while((*line)[i] != '\0')
	{
		if((*line)[i] == ';')
		{
			x = 1;
			while((*line)[i + x] == ' ')
				x++;
			if((*line)[i + x] == ';')
			{
				remove_empty_command(line, 0, x);
				i = 0;
			}
			else
				i++;
		}
		if ((*line)[i] != '\0')
			i++;
	}
}

void	remove_empty_command(char **line, int i, int empty)
{
	char *new_str;
	int len;

	len = ft_strlen((*line)) + 1;
	new_str = (char*)malloc(sizeof(char) * (len - empty));
// 	CLEAR STRUCT WHEN FAIL
//
	while((*line)[i] != '\0')
	{
		new_str[i] = (*line)[i];
		i++;
		if ((*line)[i] == ';' && (*line)[i + empty] == ';')
			break ;
	}
	new_str[i] = (*line)[i];
	i++;
	while((*line)[i + empty] != '\0')
	{
		new_str[i] = (*line)[i + empty];
		i++;
	}
	new_str[i] = '\0';
	free((*line));
	*line = new_str;
}
