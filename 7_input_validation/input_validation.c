/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:52:27 by rbakker           #+#    #+#             */
/*   Updated: 2020/10/07 17:43:43 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	input_validation(t_data *data) //mixed commands need to be added
{
	char	charachter;

	charachter = 0;
	if (validate_single_quotes(data, &charachter) == -1 ||
		validate_double_quotes(data, &charachter) == -1 ||
		validate_input_redirection(data, &charachter) == -1 ||
		validate_output_redirection(data, &charachter) == -1 ||
		validate_pipes(data, &charachter) == -1 ||
		validate_command_seperators(data, &charachter) == -1 ||
		validate_end_of_line_command(data, &charachter, 0) == -1 ||
		validate_start_of_line_command(data, &charachter) == -1)
		validation_error(data, charachter);
}

int		validate_command_seperators(t_data *data, char *charachter)
{
	int i;

	i = 0;
	(*charachter) = ';';
	while (data->input[i] != '\0')
	{
		if (data->input[i] == ';' && data->input[i + 1] == ';')
			return (-1);
		else
			(data->input[i] == '\\') ? i += 2 : i++;
	}
	return (0);
}

int		validate_end_of_line_command(t_data *data, char *charachter, int len)
{
	len = ft_strlen(data->input);
	while (data->input[len - 1] == ' ')
		len--;
	if (data->input[len - 1] == '<')
	{
		(*charachter) = '<';
		return (-1);
	}
	else if (data->input[len - 1] == '>')
	{
		(*charachter) = '>';
		return (-1);
	}
	else if (data->input[len - 1] == '<')
	{
		(*charachter) = '|';
		return (-1);
	}
	else if (data->input[len - 1] == '\\')
	{
		(*charachter) = '\\';
		return (-1);
	}
	else
		return (0);
}

int		validate_start_of_line_command(t_data *data, char *charachter)
{
	int i;

	i = 0;
	while (data->input[i] == ' ')
		i++;
	if (data->input[i] == ';')
	{
		(*charachter) = ';';
		return (-1);
	}
	else if (data->input[i] == '|')
	{
		(*charachter) = '|';
		return (-1);
	}
	else
		return (0);
}
