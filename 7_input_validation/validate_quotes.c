/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_quotes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/07 14:49:19 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/26 17:29:13 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		validate_single_quotes(t_data *data, char *character)
{
	int i;

	i = 0;
	(*character) = '\'';
	while (data->input[i] != '\0')
	{
		if (data->input[i] == '\'')
		{
			i++;
			while (data->input[i] != '\'' && data->input[i] != '\0')
				i++;
			if (data->input[i] == '\0')
				return (-1);
			i++;
		}
		else
			(data->input[i] == '\\') ? i += 2 : i++;
	}
	return (0);
}

int		validate_double_quotes(t_data *data, char *character)
{
	int i;

	i = 0;
	(*character) = '\"';
	while (data->input[i] != '\0')
	{
		if (data->input[i] == '\"')
		{
			i++;
			while (data->input[i] != '\"')
			{
				if (data->input[i] == '\\')
					i += 2;
				if (data->input[i] == '\0' || (data->input[i] == ';' &&\
				later_quotes_nb(data, i, *character) == 0))
					return (-1);
				i++;
			}
			i++;
		}
		else
			(data->input[i] == '\\') ? i += 2 : i++;
	}
	return (0);
}

int		later_quotes_nb(t_data *data, int i, char character)
{
	int count;

	count = 0;
	while (data->input[i] != '\0')
	{
		if (data->input[i] == character)
			count++;
		i++;
	}
	return (count);
}
