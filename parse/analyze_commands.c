/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   analyze_commands.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 15:56:23 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 14:03:23 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	small_command(t_data *data, char *command, int index)
{
	char **token;

	token = ft_split(command, ' ');
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command = (t_command**)malloc(sizeof(t_command*) * 1);
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command[0] = (t_command*)malloc(sizeof(t_command) * 1);
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command[0]->small.command = token[0];
	data->table[index]->command[0]->small.exit_code = 0;
	printf("command in small struct : %s\n", data->table[index]->command[0]->small.command);
	return ;
}

void	average_command(t_data *data, char *command, int index)
{
	int id;
	char **token;

	id = 1;
	token = ft_split(command, ' ');
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command = (t_command**)malloc(sizeof(t_command*) * 1);
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command[0] = (t_command*)malloc(sizeof(t_command) * 1);
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command[0]->average.command = token[0];
	if (option_check(token[1]) == 0)
	{
		data->table[index]->command[0]->average.option = token[1][1];
		data->table[index]->command[0]->average.input = token[2];
	}
	else
	{
		data->table[index]->command[0]->average.option = 0;
		data->table[index]->command[0]->average.input = token[1];
	}
	data->table[index]->command[0]->average.exit_code = 0;
	printf("command in average struct : %s\n", data->table[index]->command[0]->average.command);
	printf("option in average struct : %c\n", data->table[index]->command[0]->average.option);
	printf("input in average struct : %s\n", data->table[index]->command[0]->average.input);
	return ;
}

void	big_command(t_data *data, char *command, int index)
{

	if (data && command && index)
	return ;
}
