/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/19 13:23:31 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/08 16:34:18 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**save_commands(char *line, char command_amount, int i, int index)
{
	char 	**commands;
	int		len;

	commands = (char**)malloc(sizeof(char*) * (command_amount + 1));
	if (commands == NULL)
		return (0);
	while (line[i] != '\0' && index < command_amount)
	{
		len = len_command(line, i, 0);
		if (check_for_empty_command(line, i) == 0)
		{
			commands[index] = ft_substr(line, i, len);
			if (commands[index] == NULL)
			{
				free_array(commands);
				return (0);
			}
			printf("command [%d] = [%s]\n", index, commands[index]); //TAKE OUT!!!
			index++;
		}
		i += len;
		if (line[i] != '\0')
			i++;
	}
	commands[index] = 0;
	return (commands);
}

int		len_command(char *line, int i, int len)
{
	while (line[i + len] != ';' && line[i + len] != '\0')
	{
		if (line[i + len] == '\\')
			i += 2;
		else
			len++;
	}
	return (len);
}

int		check_for_empty_command(char *line, int i)
{
	while (line[i] != ';' && line[i] != '\0')
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
