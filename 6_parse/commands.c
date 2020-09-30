/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/19 13:23:31 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/30 11:23:55 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**save_commands(char *line, char command_amount, int i, int index)
{
	char 	**commands;
	int		len;

	commands = (char**)malloc(sizeof(char*) * (command_amount + 1));
// 	CLEAR STRUCT WHEN FAIL
//
	while (line[i] != '\0' && index < command_amount)
	{
		len = len_command(line, i, 0);
		if (empty_command(line, i) == 0)
		{
			commands[index] = (char*)malloc(sizeof(char) * len);
// 			CLEAR STRUCT WHEN FAIL
//
			commands[index] = ft_substr(line, i, len);
			printf("command [%d] = [%s]\n", index, commands[index]);
// 			CLEAR STRUCT WHEN FAIL
//
			index++;
		}
		i += len;
		if(line[i] != '\0')
			i++;
	}
	commands[index] = 0;
	return(commands);
}

int		len_command(char *line, int i, int len)
{
	while(line[i + len] != ';' && line[i + len] != '\0')
	{
		len++;
		if (line[i + len] == ';' && line[i + len - 1] == '\\')
			len++;
	}
	return (len);
}

int		empty_command(char *line, int i)
{
	while(line[i] != ';' && line[i] != '\0')
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
