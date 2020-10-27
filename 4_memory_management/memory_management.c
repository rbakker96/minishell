/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/22 13:51:43 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/26 19:24:01 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*g_dir_path;
int		g_exit_code;
int		g_pid;

void	initialize(t_data *data)
{
	data->input = NULL;
	data->commands = NULL;
	data->args = NULL;
	data->envp = NULL;
	g_exit_code = 0;
	g_pid = 0;
	g_dir_path = get_current_directory(data);
}

void	clear_memory(t_data *data)
{
	free_command_table(data);
	free_string(g_dir_path);
	free_string(data->input);
	free_array(data->envp);
	//free_array(data->args);
}

void	clear_used_memory(t_data *data)
{
	free_command_table(data);
	free_string(data->input);
	free_array(data->args);
	data->commands = NULL;
	data->input = NULL;
	data->args = NULL;
}
