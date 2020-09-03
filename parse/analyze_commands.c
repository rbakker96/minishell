/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   analyze_commands.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 15:56:23 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 11:08:40 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	small_command(t_data *data, char *command, int index)
{
	int token;
	char **structure;

	token = 0;
	structure = ft_split(command, ' ');
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command = (t_command**)malloc(sizeof(t_command*) * (1));
	data->table[index]->command[token] = (t_command*)malloc(sizeof(t_command) * (2));
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command[token]->small.command = "pwd";
	data->table[index]->command[token]->small.exit_code = 0;
	printf("stored in struct : %s\n", data->table[index]->command[token]->small.command);
	return ;
}

void	average_command(t_data *data, char *command, int index)
{
	if (data && command && index)
	return ;
}

void	big_command(t_data *data, char *command, int index)
{

	if (data && command && index)
	return ;
}
