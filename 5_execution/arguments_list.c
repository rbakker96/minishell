/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arguments_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/07 11:15:58 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/12 11:26:47 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_array(char **array)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (array[size] != 0)
		size++;
	while (i < size)
	{
		printf("final token [%d] = %s\n", i, array[i]);
		i++;
	}
}

void	update_arguments_list(t_data *data, int cmd, int tkn, int x)
{
	int		usable_tokens;
	char	**tokens;

	usable_tokens = count_usable_tokens(data, cmd, 0);
	tokens = malloc(sizeof(char*) * (usable_tokens + 1));
	if (tokens == NULL)
		malloc_error(data, data->commands[cmd]->token_amount, 0);
	x = 0;
	while (x < usable_tokens)
	{
		if (pipe_check(data->commands[cmd]->tokens, tkn) == -1)
			tkn += 2;
		else if (save_list_element(data->commands[cmd]->tokens[tkn], &tokens[x],
				&tkn, &x) == 0)
			malloc_error(data, data->commands[cmd]->token_amount, tokens);
	}
	tokens[x] = 0;
	free_array(data->commands[cmd]->tokens);
	data->commands[cmd]->tokens = tokens;
	data->commands[cmd]->token_amount = usable_tokens;
	print_array(data->commands[cmd]->tokens); // remove later
}

int		save_list_element(char *current_token, char **saved_token, int *tkn,
																		int *x)
{
	if (current_token[0] == '\0')
		(*tkn)++;
	else
	{
		(*saved_token) = ft_strdup(current_token);
		if ((*saved_token) == NULL)
			return (0);
		(*tkn)++;
		(*x)++;
	}
	return (1);
}

int		count_usable_tokens(t_data *data, int cmd, int tkn)
{
	int		amount;

	amount = 0;
	while (tkn < data->commands[cmd]->token_amount)
	{
		if (data->commands[cmd]->tokens[tkn][0] == '|')
			break ;
		if (data->commands[cmd]->tokens[tkn][0] == '\0')
			tkn++;
		else if (redirection(data->commands[cmd]->tokens[tkn]) > 5)
			tkn += 2;
		else
		{
			tkn++;
			amount++;
		}
	}
	while (tkn < data->commands[cmd]->token_amount)
	{
		tkn++;
		amount++;
	}
	return (amount);
}