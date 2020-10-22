/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arguments_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/07 11:15:58 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/22 13:19:30 by rbakker       ########   odam.nl         */
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

int		update_token_list(t_data *data, int cmd, int *tkn)
{
	int		usable_tokens;
	char	**tokens;
	int		i;

	i = 0;
	usable_tokens = count_usable_tokens(data, cmd, (*tkn));
	printf("usable tokens = %d\n", usable_tokens);
	tokens = malloc(sizeof(char*) * (usable_tokens + 1));
	if (tokens == NULL)
		malloc_error(data, data->commands[cmd]->token_nb, 0);
	while (i < usable_tokens)
	{
		if (check_token_usability(data->commands[cmd]->tokens, (*tkn)) == -1)
			(*tkn) += 2;
		else if (save_list_element(data->commands[cmd]->tokens[(*tkn)],
											&tokens[i], tkn, &i) == -1)
			malloc_error(data, data->commands[cmd]->token_nb, tokens);
	}
	tokens[i] = 0;
	free_array(data->commands[cmd]->tokens);
	data->commands[cmd]->tokens = tokens;
	data->commands[cmd]->token_nb = usable_tokens;
	(*tkn) = 0;
	if (usable_tokens == 0)
		return (-1);
	return (0);
	print_array(data->commands[cmd]->tokens); // remove later
}

int		save_list_element(char *old_token, char **new_token, int *tkn, int *x)
{
	(*new_token) = ft_strdup(old_token);
	if ((*new_token) == NULL)
		return (-1);
	(*tkn)++;
	(*x)++;
	return (0);
}

int		count_usable_tokens(t_data *data, int cmd, int tkn)
{
	int		amount;

	amount = 0;
	while (tkn < data->commands[cmd]->token_nb)
	{
		if (data->commands[cmd]->tokens[tkn][0] == '|')
			break ;
		else if (redirection(data->commands[cmd]->tokens[tkn]) > piped)
			tkn += 2;
		else
		{
			tkn++;
			amount++;
		}
	}
	while (tkn < data->commands[cmd]->token_nb)
	{
		tkn++;
		amount++;
	}
	return (amount);
}
