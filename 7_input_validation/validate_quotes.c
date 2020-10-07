/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:49:19 by rbakker           #+#    #+#             */
/*   Updated: 2020/10/07 17:26:36 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		validate_single_quotes(t_data *data, char *charachter)
{
	int i;

	i = 0;
	(*charachter) = '\'';
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
			i++;
	}
	return (0);
}

int		validate_double_quotes(t_data *data, char *charachter)
{
	int i;

	i = 0;
	(*charachter) = '\"';
	while (data->input[i] != '\0')
	{
		if (data->input[i] == '\"')
		{
			i++;
			while (data->input[i] != '\"')
			{
				if (data->input[i] == '\\')
					i += 2;
				if (data->input[i] == '\0' || data->input[i] == ';')
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
