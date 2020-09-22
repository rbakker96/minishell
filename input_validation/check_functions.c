/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 10:32:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/22 14:46:33 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	double_symbol(char *line, char c, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] == '\\')
			i += 2;
		if(line[i - 1] != '\\' && line[i] == c && line[i + 1] == c)
			parse_error(c);
		i++;
	}
}

void	double_command(char *line, char c, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] == '\\')
			i += 2;
		if (line[i] == c)
		{
			i += (line[i + 1] == c) ? 2 : 1;
			while (line[i] == ' ' && line[i] != '\0')
				i++;
			if (line[i] == c)
				parse_error(c);
		}
		i++;
	}
}

void	mixed_command(char *line, int i, int x)
{
	while (line[i] != '\0')
	{
		if (token_id(line[i]) == meta_char)
		{
			x = i;
			i++;
			while (line[i] == ' ' && line[i] != '\0')
				i++;
			if (line[x] == '|' && line[i] == '<')
				parse_error('|');
			else if (line[x] == '>' && (line[i] == '|' || line[i] == '<'))
				parse_error(line[i]);
			else if (line[x] == '<' && (line[i] == '|' || line[i] == '>'))
				parse_error(line[i]);
		}
		if (line[i] == '\\')
			i += 2;
		else
			i++;
	}
}

void	end_of_line_command(char *line, char c, int i)
{
	while(line[i] != '\0' || (line[i] == ';' && line[i - 1] != '\\'))
		i++;
	i--;
	while (line[i] == ' ')
		i--;
	if (line[i] == c && line[i - 1] != '\\')
		parse_error(c);
}

void	validate_qoute(char *line, int *i, int x)
{
	(*i)++;
	while(line[(*i)] != '\0')
	{
		if(line[(*i)] == '\\')
			(*i) += 2;
		if (token_id(line[(*i)]) == x)
			return ;
		(*i)++;
	}
	if (x == double_quote)
		parse_error('\"');
	else
		parse_error('\'');
}

void	check_first_symbol(char *line)
{
	if (line[0] == ';' && line[1] == ';')
		parse_error(';');
	if (line[0] == '\'')
		parse_error('\'');
	if (line[0] == '\"')
		parse_error('\"');
	if (line[0] == '<')
		parse_error('<');
	if (line[0] == '>')
		parse_error('>');
	if (line[0] == '|')
		parse_error('|');
}
