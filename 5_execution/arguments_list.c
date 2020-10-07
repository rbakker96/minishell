/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:15:58 by rbakker           #+#    #+#             */
/*   Updated: 2020/10/07 13:30:50 by rbakker          ###   ########.fr       */
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
		if (data->commands[i]->tokens[token] == 0)
			token++;
		if (redirection(data->commands[i]->tokens[token]) > 5)
			token += 2;
		else
		{
			tokens[x] = ft_strdup(data->commands[i]->tokens[token]);
			if (tokens[x] == NULL)
				malloc_error(data, data->commands[i]->token_amount, tokens);
			x++;
			token++;
		}
	}
	tokens[x] = 0;
	save_arguments_list(data, i, tokens, usable_tokens);
	print_array(data->commands[i]->tokens); // remove later
}

void	save_arguments_list(t_data *data, int i, char **tokens,
															int usable_tokens)
{
	free_array(data->commands[i]->tokens);
	data->commands[i]->tokens = tokens;
	data->commands[i]->token_amount = usable_tokens;
}

int		identfiy_usable_tokens(t_data *data, int i, int token)
{
	int		amount;

	amount = 0;
	while (token < data->commands[i]->token_amount)
	{
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
	return (amount);
}
