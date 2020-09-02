/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   analyze_commands.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 15:56:23 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/02 17:53:11 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	small_command(t_data *data, char *command, int index)
{
	int token;
	char **structure;

	token = 0;
	structure = ft_split(command, ' ');
	data->table[index]->command[token]->small.command = "pwd";
	data->table[index]->command[token]->small.exit_code = 0;
	printf("stored in struct : %s\n", data->table[index]->command[token]->small.command);
	return ;
}

void	average_command(t_data *data, char *command, int index)
{
	printf("test");
	if (data && command && index)
	return ;
}

void	big_command(t_data *data, char *command, int index)
{
	printf("sadfasdf");
	if (data && command && index)
	return ;
}
