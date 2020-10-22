/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_command_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:00:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/22 15:00:16 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		parse_command(t_data *data, char **envp)
{
	int ret;

	ret = 0;
	if (!data->envp)
		save_environment_variables(data, envp);
	ret = get_next_line(0, &data->input);
	if (ret == -1 || input_validation(data) == -1)
		return (-1);
	if (ret == 0)
	{
		clear_memory(data);
		write(1, "exit\n", 5);
		exit(0);
	}
	create_command_table(data, data->input, 0);
	return (0);
}

int		save_environment_variables(t_data *data, char **envp)
{
	int		index;
	int		envp_size;
	char	**malloced_envp;

	index = 0;
	envp_size = get_array_size(envp);
	malloced_envp = (char**)malloc(sizeof(char*) * (envp_size + 1));
	if (malloced_envp == NULL)
		envp_malloc_error(data, 0);
	while (index < envp_size)
	{
		malloced_envp[index] = ft_strdup(envp[index]);
		if (malloced_envp[index] == NULL)
			envp_malloc_error(data, malloced_envp);
		index++;
	}
	malloced_envp[index] = 0;
	data->envp = malloced_envp;
	data->args = 0;
	return (0);
}

int		create_command_table(t_data *data, char *line, int cmd)
{
	char	**commands;

	data->command_nb = get_amount_of_commands(line, 0);
	data->commands = (t_command_table**)malloc(sizeof(t_command_table*) *
													(data->command_nb + 1));
	if (data->commands == NULL)
		malloc_error(data, 0, 0);
	commands = save_commands(line, data->command_nb, 0, 0);
	if (commands == NULL)
		malloc_error(data, 0, 0);
	while (cmd < data->command_nb)
	{
		if (save_single_command(data, commands, cmd) == -1)
			malloc_error(data, cmd, commands);
		cmd++;
	}
	data->commands[cmd] = NULL;
	free_array(commands);
	return (0);
}

int		save_single_command(t_data *data, char **commands, int cmd)
{
	data->commands[cmd] = (t_command_table*)malloc(sizeof(t_command_table) * 1);
	if (data->commands[cmd] == NULL)
		return (-1);
	data->commands[cmd]->token_nb = get_amount_of_tokens(commands[cmd], 0, 0);
	printf("token amount = %d\n", data->commands[cmd]->token_nb); //TAKE OUT
	data->commands[cmd]->tokens = (char**)malloc(sizeof(char*) *
									(data->commands[cmd]->token_nb + 1));
	if (data->commands[cmd]->tokens == NULL)
		return (-1);
	save_tokens(data, commands, commands[cmd], cmd);
	return (0);
}
