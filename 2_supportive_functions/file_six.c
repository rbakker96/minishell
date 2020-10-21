/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_six.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 13:11:44 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/21 13:57:01 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		compare_command(char *command, char *token_command, int len)
{
	int token_len;

	token_len = ft_strlen(token_command);
	if (token_len != len)
		return (-1);
	return (ft_strncmp(command, token_command, len));
}

int		check_token_usability(char **tokens, int i)
{
	int x;

	x = i;
	while (x > 0)
	{
		if (tokens[x][0] == '|')
			return (0);
		x--;
	}
	if (compare_command("<", tokens[i], 1) == 0 ||
		compare_command(">", tokens[i], 1) == 0 ||
		compare_command(">>", tokens[i], 2) == 0)
		return (-1);
	else
		return (0);
}

int		calculate_needed_tokens(t_data *data, int cmd, int tkn)
{
	int		count;
	char	*value;

	count = 0;
	value = data->commands[cmd]->tokens[tkn];
	while (value != NULL && value[0] != '|')
	{
		count++;
		tkn++;
		value = data->commands[cmd]->tokens[tkn];
	}
	return (count);
}

void	update_token_position(t_data *data, int cmd, int *tkn)
{
	int		count;
	char	*value;

	count = 0;
	value = data->commands[cmd]->tokens[(*tkn)];
	if (value == NULL)
		return ;
	while (value[0] != '|')
	{
		count++;
		(*tkn)++;
		value = data->commands[cmd]->tokens[(*tkn)];
		if (value == NULL)
			break ;
	}
	if (value == NULL)
		return ;
	else if (data->commands[cmd]->tokens[(*tkn)][0] == '|')
		(*tkn)++;
}

int		custom_cmd(t_data *data, int cmd, int tkn)
{
	char *value;

	value = data->commands[cmd]->tokens[tkn];
	if (compare_command("echo", value, 4) == 0 	 ||
		compare_command("cd", value, 2) == 0 	 ||
		compare_command("pwd", value, 3) == 0 	 ||
		compare_command("export", value, 6) == 0 ||
		compare_command("unset", value, 5) == 0  ||
		compare_command("env", value, 3) == 0 	 ||
		compare_command("exit", value, 4) == 0)
		return (1);
	else
		return (0);
}
