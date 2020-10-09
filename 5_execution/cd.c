/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/09 17:12:15 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_cd(t_data *data, int cmd, int *token, int needed_tokens)
{
	char	*value;

	(*token)++;
	// create_fd(data, cmd, (*token), &needed_tokens);
	// if (data->commands[cmd]->error_flag == -1)
	// {
	// 	if (data->commands[cmd]->tokens[needed_tokens][0] == '|')
	// 		needed_tokens++;
	// 	(*token) = needed_tokens;
	// 	return ;
	// }
	value = get_argument(data, cmd, token, needed_tokens);
	if (value == NULL)
		return ;
	else if (value[0] == '|')
		(*token) = needed_tokens + 1;
	else if (ft_strncmp("~", value, ft_strlen(value)) == 0)
		go_to_home(data, cmd, token, needed_tokens);
	else if (chdir(value) == -1)
		change_directory_error(data, value, cmd, token);
	else
		(*token) = needed_tokens;
}

char	*get_argument(t_data *data, int cmd, int *token, int needed_tokens)
{
	int	arguments;
	char *value;

	arguments = 0;
	value = data->commands[cmd]->tokens[needed_tokens];
	if (value && ft_strncmp("|", value, 1) == 0)
		return ("|");
	while ((*token) < needed_tokens)
	{
		if (redirection(data->commands[cmd]->tokens[(*token)]) > 0)
			(*token) += 2;
		else
		{
			value = data->commands[cmd]->tokens[(*token)];
			arguments++;
			(*token)++;
		}
	}
	if (arguments > 1)
	{
		print(data, 2, "minishell : cd : too many arguments\n", 0);
		(*token) = data->commands[cmd]->token_amount;
		return (0);
	}
	return (value);
}

void	go_to_home(t_data *data, int cmd, int *token, int needed_tokens)
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
		change_directory_error(data, home_path, cmd, token);
	(*token) = needed_tokens;
}
