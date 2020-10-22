/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/22 13:51:43 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/22 14:25:11 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*g_dir_path;

void	initialize(t_data *data)
{
	g_dir_path = get_current_directory(data);
}

void	clear_memory(t_data *data)
{
	free_command_table(data);
	free_string(g_dir_path);
	free_string(data->input);
	free_array(data->envp);
	free_array(data->args);
}

void	clear_used_memory(t_data *data)
{
	free_command_table(data);
	//free_string(g_dir_path);
	free_string(data->input);
	//free_array(data->envp);
	free_array(data->args);
}
