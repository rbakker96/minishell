/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_command_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:00:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/05 15:10:09 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse_command(t_data *data, char **envp)
{
	char 	*line;

	save_environment_variables(data, envp);
	if (get_next_line(0, &line) == -1)
		return (-1);
	// if (input_validation(&line) == -1)
	// {
	// 	free(line);
	// 	return (-1);
	// }
	create_command_table(data, line, 0);
	free(line);
	return (0);
}

int		save_environment_variables(t_data *data, char **envp)
{
	int index;
	int envp_size;
	char **malloced_envp;

	index = 0;
	envp_size = get_array_size(envp);
	malloced_envp = (char**)malloc(sizeof(char*) * (envp_size + 1));
	while (index < envp_size)
	{
		malloced_envp[index] = ft_strdup(envp[index]);
		if (malloced_envp[index] == NULL)
		{
			free_array(malloced_envp);
			print(data, 2, "minishell : error due to malloc failure\n", 0);
			exit(1);
		}
		index++;
	}
	malloced_envp[index ] = 0;
	data->envp = malloced_envp;
	return (0);
}

int		create_command_table(t_data *data, char *line, int i)
{
	char	**commands;

	data->command_amount = get_amount_of_commands(line, 1);
	printf("command amount = %d\n", data->command_amount); //TAKE OUT!!!
	data->commands = (t_command_table**)malloc(sizeof(t_command_table*) * (data->command_amount + 1));
	if (data->commands == NULL)
		malloc_error(data, 0, 0);
	commands = save_commands(line, data->command_amount, 0, 0);
	if (commands == NULL)
		malloc_error(data, 0, 0);
	while(i < data->command_amount)
	{
		data->commands[i] = (t_command_table*)malloc(sizeof(t_command_table) * 1);
		if (data->commands[i] == NULL)
			malloc_error(data, i, commands);
		data->commands[i]->token_amount = get_amount_of_tokens(commands[i], 0, 0);
		printf("token amount = %d\n", data->commands[i]->token_amount); //TAKE OUT!!!
		data->commands[i]->tokens = (char**)malloc(sizeof(char*) * (data->commands[i]->token_amount + 1));
		if (data->commands[i]->tokens == NULL)
			malloc_error(data, i, commands);
		save_tokens(data, commands, commands[i], i, 0);
		i++;
	}
	data->commands[i] = NULL;
	free_array(commands);
	return (0);
}
