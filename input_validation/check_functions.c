/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 10:32:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/17 12:39:17 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dubbel_symbol(char *line, char c, int i)
{
	while (line[i] != '\0')
	{
		if(line[i] == c && line[i + 1] == c )
			parse_error(c);
		i++;
	}
}

void	dubbel_command(char *line, char c, int i)
{
	while (line[i] != '\0')
	{
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
		if (token_id(line[i]) == 1)
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
		i++;
	}
}

void	end_of_line_command(char *line, char c, int i)
{
	while(line[i] != '\0' && line[i] != ';')
		i++;
	i--;
	while (line[i] == ' ')
		i--;
	if (line[i] == c)
		parse_error(c);
}

void	validate_qoute(char *line, int *i, int x)
{
	(*i)++;
	while(line[(*i)] != '\0')
	{
		if (token_id(line[(*i)]) == x && line[(*i) - 1] != '\\')
			return ;
		(*i)++;
	}
	if (x == 2)
		parse_error('\"');
	else
		parse_error('\'');
}
