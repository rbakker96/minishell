/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_six.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 13:11:44 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/12 15:35:10 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		pipe_check(char **tokens, int i)
{
	int x;

	x = i;
	while (x > 0)
	{
		if (tokens[x][0] == '|')
			return (0);
		x--;
	}
	if (tokens[i][0] == '\0')
		return (0);
	if (ft_strncmp(tokens[i], "<", ft_strlen(tokens[i]) == 0 ||
		ft_strncmp(tokens[i], ">", ft_strlen(tokens[i])) == 0 ||
		ft_strncmp(tokens[i], ">>", ft_strlen(tokens[i])) == 0))
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
	return (count++);
}

void	update_token_position(t_data *data, int cmd, int *tkn)
{
	char	*value;

	value = data->commands[cmd]->tokens[(*tkn)];
	if (value == NULL)
		return ;
	else if (data->commands[cmd]->tokens[(*tkn)][0] == '|')
		(*tkn)++;
	return ;
}
