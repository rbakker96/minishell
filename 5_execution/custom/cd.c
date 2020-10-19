/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/19 15:54:21 by qli           ########   odam.nl         */
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
		go_to_home(data, cmd);
	else if (chdir(value) == -1) // print out errno
		print_errno_str(data, cmd, value);
}

void	go_to_home(t_data *data, int cmd)
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
		print_errno_str(data, cmd, home_path);
}
