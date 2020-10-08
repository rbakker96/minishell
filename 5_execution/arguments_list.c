/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arguments_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/07 11:15:58 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/08 16:13:59 by rbakker       ########   odam.nl         */
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

void	update_arguments_list(t_data *data, int i, int token, int x)
{
	int		usable_tokens;
	char	**tokens;

	usable_tokens = identfiy_usable_tokens(data, i, 0);
	tokens = malloc(sizeof(char*) * usable_tokens + 1);
	if (tokens == NULL)
		malloc_error(data, data->commands[i]->token_amount, 0);
	x = 0;
	while (x < usable_tokens)
	{
		if (pipe_check(data->commands[i]->tokens, token) == -1)
			token += 2;
		else if (save_list_element(data->commands[i]->tokens[token], &tokens[x],
				&token, &x) == 0)
			malloc_error(data, data->commands[i]->token_amount, tokens);
	}
	tokens[x] = 0;
	free_array(data->commands[i]->tokens);
	data->commands[i]->tokens = tokens;
	data->commands[i]->token_amount = usable_tokens;
	print_array(data->commands[i]->tokens); // remove later
}

int		save_list_element(char *current, char **new, int *token, int *x)
{
	if (current[0] == '\0')
		(*token)++;
	else
	{
		(*new) = ft_strdup(current);
		if ((*new) == NULL)
			return (0);
		(*token)++;
		(*x)++;
	}
	return (1);
}

int		identfiy_usable_tokens(t_data *data, int i, int token)
{
	int		amount;

	amount = 0;
	while (token < data->commands[i]->token_amount)
	{
		if (data->commands[i]->tokens[token][0] == '|')
			break ;
		if (data->commands[i]->tokens[token][0] == '\0')
			token++;
		else if (redirection(data->commands[i]->tokens[token]) > 5)
			token += 2;
		else
		{
			token++;
			amount++;
		}
	}
	while (token < data->commands[i]->token_amount)
	{
		token++;
		amount++;
	}
	return (amount);
}
