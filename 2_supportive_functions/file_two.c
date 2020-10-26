/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_two.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 12:50:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/26 20:18:10 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_amount_of_commands(char *line, int i)
{
	int count;

	count = 0;
	while (line[i] != '\0')
	{
		while (ft_isspace(line[i]) == 1)
			i++;
		if (line[i] != '\0' && line[i] != ';')
			count++;
		while (line[i] != '\0' && line[i] != ';')
		{
			if (char_type(line[i]) == single_quote ||
				char_type(line[i]) == double_quote)
				process_quotes(line, &i);
			(line[i] == '\\') ? i += 2 : i++;
		}
		if (line[i] != '\0')
			i++;
	}
	return (count);
}

void	process_quotes(char *line, int *i)
{
	int	quote;

	quote = char_type(line[(*i)]);
	(*i)++;
	while (char_type(line[(*i)]) != quote)
		(line[(*i)] == '\\') ? (*i) += 2 : (*i)++;
}

int		get_amount_of_tokens(char *command, int cmd, int tkn)
{
	while (ft_isspace(command[cmd]) == 1 && command[cmd] != '\0')
		cmd++;
	while (command[cmd] != '\0')
	{
		if (ft_isspace(command[cmd]) == 1)
			cmd++;
		else if (char_type(command[cmd]) == meta_char)
			meta_token(command, &cmd, &tkn);
		else
			normal_token(command, &cmd, &tkn);
	}
	if (tkn == 0)
		return (1);
	return (tkn);
}

int			char_type(char c)
{
	if (ft_isspace(c) == 1)
		return (space);
	else if (c == '>' || c == '<' || c == '|')
		return (meta_char);
	else if (c == '\"')
		return (double_quote);
	else if (c == '\'')
		return (single_quote);
	else
		return (normal_char);
}
