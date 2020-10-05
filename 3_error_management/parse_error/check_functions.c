/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 10:32:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/02 20:05:33 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	double_symbol(char *line, char c, int i, int *ret)
{
	while (line[i] != '\0')
	{
		if (line[i] == '\\')
			i += 2;
		if(line[i - 1] != '\\' && line[i] == c && line[i + 1] == c)
			print_error(c, ret);
		i++;
	}
}

void	double_command(char *line, char c, int i, int *ret)
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
				print_error(c, ret);
		}
		i++;
	}
}

void	mixed_command(char *line, int i, int x, int *ret)
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
				print_error('|', ret);
			else if (line[x] == '>' && (line[i] == '|' || line[i] == '<'))
				print_error(line[i], ret);
			else if (line[x] == '<' && (line[i] == '|' || line[i] == '>'))
				print_error(line[i], ret);
		}
		if (line[i] == '\\')
			i += 2;
		else
			i++;
	}
}

void	end_of_line_command(char *line, char c, int i, int *ret)
{
	while(line[i] != '\0' || (line[i] == ';' && line[i - 1] != '\\'))
		i++;
	i--;
	while (line[i] == ' ')
		i--;
	if (line[i] == c && line[i - 1] != '\\')
		print_error(c, ret);
}

void	validate_qoute(char *line, int *i, int x, int *ret)
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
		print_error('\"', ret);
	else
		print_error('\'', ret);
}

void	check_first_symbol(char *line, int *ret)
{
	if (line[0] == ';' && line[1] == ';')
		print_error(';', ret);
	if (line[0] == '\'')
		print_error('\'', ret);
	if (line[0] == '\"')
		print_error('\"', ret);
	if (line[0] == '<')
		print_error('<', ret);
	if (line[0] == '>')
		print_error('>', ret);
	if (line[0] == '|')
		print_error('|', ret);
}
