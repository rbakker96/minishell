/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/12 11:42:30 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_cd(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	char	*value;

	(*tkn)++;
	value = get_argument(data, cmd, tkn, needed_tokens);
	if (value == NULL)
		return ;
	else if (value[0] == '|')
		(*tkn) = needed_tokens + 1;
	else if (ft_strncmp("~", value, ft_strlen(value)) == 0)
		go_to_home(data, cmd, tkn, needed_tokens);
	else if (chdir(value) == -1)
		change_directory_error(data, value, cmd, tkn);
	else
		(*tkn) = needed_tokens;
}

char	*get_argument(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	int		arguments;
	char	*value;

	arguments = 0;
	value = data->commands[cmd]->tokens[needed_tokens];
	if (value && ft_strncmp("|", value, 1) == 0)
		return ("|");
	while ((*tkn) < needed_tokens)
	{
		if (redirection(data->commands[cmd]->tokens[(*tkn)]) > 0)
			(*tkn) += 2;
		else
		{
			value = data->commands[cmd]->tokens[(*tkn)];
			arguments++;
			(*tkn)++;
		}
	}
	if (arguments > 1)
	{
		print(data, 2, "minishell : cd : too many arguments\n", 0);
		(*tkn) = data->commands[cmd]->token_amount;
		return (0);
	}
	return (value);
}

void	go_to_home(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	char	*home_path;
	int		x;

	x = 0;
	while (data->envp[x] != NULL)
	{
		if (ft_strncmp("HOME", data->envp[x], 4) == 0)
			home_path = data->envp[x] + 5;
		x++;
	}
	if (chdir(home_path) == -1)
		change_directory_error(data, home_path, cmd, tkn);
	(*tkn) = needed_tokens;
}
