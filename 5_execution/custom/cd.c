/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/19 14:44:59 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_cd(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	char	*value;

	needed_tokens = calculate_needed_tokens(data, cmd, (*tkn));
	(*tkn)++;
	value = data->commands[cmd]->tokens[(*tkn)];
	if (data->commands[cmd]->tokens[needed_tokens] != NULL &&
		data->commands[cmd]->tokens[needed_tokens][0] == '|')
		(*tkn) = needed_tokens;
	// else if (needed_tokens > 2)
	// 	print(data, 2, "minishell : cd : too many arguments\n", 0);
	// too many arguments still works --> error when directory does not exist --> opendir function
	else if (needed_tokens == 1 || compare_command("~", value, 1) == 0)
		go_to_home(data);
	else if (chdir(value) == -1) // print out errno
		change_directory_error(data, value);
	(*tkn) = needed_tokens;
	update_token_position(data, cmd, tkn); // stil needed in child process?
	printf("test\n");
}

void	go_to_home(t_data *data)
{
	char	*home_path;
	int		x;

	x = 0;
	while (data->envp[x] != NULL)
	{
		if (ft_strncmp("HOME", data->envp[x], 4) == 0)
		{
			home_path = data->envp[x] + 5;
			break ;
		}
		x++;
	}
	if (chdir(home_path) == -1)
		change_directory_error(data, home_path);
}
