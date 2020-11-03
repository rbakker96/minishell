/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/11/03 10:25:59 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_cd(t_data *data, int cmd, int tkn, int needed_tokens)
{
	char	*value;

	needed_tokens = calculate_needed_tokens(data, cmd, tkn);
	tkn++;
	value = data->commands[cmd]->tokens[tkn];
	if (data->commands[cmd]->tokens[needed_tokens] != NULL &&
		data->commands[cmd]->tokens[needed_tokens][0] == '|')
		tkn = needed_tokens;
	if (needed_tokens > 2)
	{
		if (cd_multiple_args(data, cmd, &tkn, needed_tokens) == 0)
			value = data->commands[cmd]->tokens[tkn];
		else
			return ;
	}
	if (needed_tokens == 1 || compare_command("~", value, 1) == 0 ||
		value[0] == '\0' || ft_strncmp("~/", value, 2) == 0)
		go_to_home(data, cmd, value, needed_tokens);
	else if (chdir(value) == -1)
		print_errno(data, cmd, value, 1);
	free(g_dir_path);
	g_dir_path = get_current_directory(data);
}

int		cd_multiple_args(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	int		token;
	char	*value;

	value = data->commands[cmd]->tokens[needed_tokens];
	token = *tkn;
	while (needed_tokens > 0 && token < data->commands[cmd]->token_nb)
	{
		if (data->commands[cmd]->tokens[token][0] == '\0')
			needed_tokens--;
		else
			*tkn = token;
		if (value != NULL && value[0] == '|')
			token--;
		else
			token++;
	}
	if (needed_tokens > 2)
	{
		print(data, 2, "minishell : cd : too many arguments\n", 0);
		g_exit_code = 1;
		return (-1);
	}
	return (0);
}

void	go_to_home(t_data *data, int cmd, char *value, int needed_tokens)
{
	char	*home_path;
	int		x;
	int		updated_home_path;

	x = 0;
	updated_home_path = 0;
	while (data->envp[x] != NULL)
	{
		if (ft_strncmp("HOME", data->envp[x], 4) == 0)
		{
			home_path = data->envp[x] + 5;
			break ;
		}
		x++;
	}
	if (needed_tokens > 1 && ft_strlen(value) > 2 &&
		ft_strncmp("~/", value, 2) == 0)
	{
		home_path = expand_home_path(data, value, home_path);
		updated_home_path = 1;
	}
	if (chdir(home_path) == -1)
		print_errno(data, cmd, home_path, 1);
	if (updated_home_path == 1)
		free(home_path);
}

char	*expand_home_path(t_data *data, char *value, char *home_path)
{
	char	*sub_path;
	char	*updated_home_path;

	sub_path = ft_substr(value, 1, ft_strlen(value) - 1);
	if (sub_path == NULL)
		malloc_error(data, 0);
	updated_home_path = ft_strjoin(home_path, sub_path);
	if (updated_home_path == NULL)
		malloc_error(data, &sub_path);
	free(sub_path);
	return (updated_home_path);
}
