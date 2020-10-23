/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/07 13:52:27 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/23 13:05:22 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		input_validation(t_data *data)
{
	char	character;

	character = 0;
	if (validate_single_quotes(data, &character) == -1 ||
		validate_double_quotes(data, &character) == -1 ||
		validate_end_of_line_command(data, &character, 0) == -1)
	{
		validation_error(data, character, 1);
		return (-1);
	}
	if (validate_input_redirection(data, &character) == -258 ||
		validate_output_redirection(data, &character) == -258 ||
		validate_pipes(data, &character) == -258 ||
		validate_command_seperators(data, &character) == -258 ||
		validate_end_of_line_command(data, &character, 0) == -258 ||
		validate_start_of_line_command(data, &character) == -258)
	{
		validation_error(data, character, 258);
		return (-1);
	}
	return (0);
}

int		validate_command_seperators(t_data *data, char *character)
{
	int i;

	i = 0;
	(*character) = ';';
	while (data->input[i] != '\0')
	{
		if (data->input[i] == ';' && data->input[i + 1] == ';')
			return (-258);
		else
			(data->input[i] == '\\') ? i += 2 : i++;
	}
	return (0);
}

int		validate_end_of_line_command(t_data *data, char *character, int len)
{
	len = ft_strlen(data->input);
	while (data->input[len - 1] == ' ')
		len--;
	if (data->input[len - 1] == '<')
	{
		(*character) = '<';
		return (-258);
	}
	else if (data->input[len - 1] == '>')
	{
		(*character) = '>';
		return (-258);
	}
	else if (data->input[len - 1] == '|')
	{
		(*character) = '|';
		return (-258);
	}
	else if (data->input[len - 1] == '\\')
	{
		(*character) = '\\';
		return (-1);
	}
	else
		return (0);
}

int		validate_start_of_line_command(t_data *data, char *character)
{
	int i;

	i = 0;
	while (data->input[i] == ' ')
		i++;
	if (data->input[i] == ';')
	{
		(*character) = ';';
		return (-258);
	}
	else if (data->input[i] == '|')
	{
		(*character) = '|';
		return (-258);
	}
	else
		return (0);
}
