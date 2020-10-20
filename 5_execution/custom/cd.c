/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/20 11:13:22 by rbakker       ########   odam.nl         */
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
	if (directory_validation(data, cmd, (*tkn), needed_tokens) == -1)
		return ;
	// else if (needed_tokens > 2)
	// 	print(data, 2, "minishell : cd : too many arguments\n", 0);
	// too many arguments still works --> error when directory does not exist --> opendir function
	if (needed_tokens == 1 || compare_command("~", value, 1) == 0)
		go_to_home(data, cmd);
	else if (chdir(value) == -1)
		print_errno(data, cmd, value, 1);
}

int		directory_validation(t_data *data, int cmd, int tkn, int needed_tokens)
{
	char	*directory;
	DIR		*dirp;

	while (tkn < needed_tokens)
	{
		directory = data->commands[cmd]->tokens[tkn];
		dirp = opendir(directory);
		if (dirp == NULL)
		{
			print_errno(data, cmd, directory, 1);
			return (-1);
		}
		closedir(dirp);
		tkn++;
	}
	return (0);
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
		print_errno(data, cmd, home_path, 1);
}
