/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/03 15:19:55 by qli           #+#    #+#                 */
/*   Updated: 2020/09/19 15:00:51 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void 	check_input_redirection(char *line)
{
	double_symbol(line, '<', 1);
	double_command(line, '<', 1);
	end_of_line_command(line, '<', 1);
}

void	check_output_redirection(char *line)
{
	double_command(line, '>', 1);
	end_of_line_command(line, '>', 1);
}

void	check_pipes(char **line, int i)
{
	char *str;

	double_command((*line), '|', 1);
	end_of_line_command((*line), '|', 1);
	while ((*line)[i] != '\0')
	{
		if((*line)[i - 1] != '\\' && (*line)[i] == '|' && (*line)[i + 1] == '|' )
		{
			str = ft_substr((*line), 0, i);
			free((*line));
			*line = str;
		}
		i++;
	}
}

void	check_multiline_commands(char *line, int i)
{
	while (line[i] != '\0')
	{
		if ((token_id(line[i]) == 2 || token_id(line[i]) == 3) && i == 0)
			validate_qoute(line, &i, token_id(line[i]));
		else if ((token_id(line[i]) == 2 || token_id(line[i]) == 3) && line[i - 1] != '\\')
			validate_qoute(line, &i, token_id(line[i]));
		i++;
	}
}

void	input_validation(char **line)
{
	check_first_symbol((*line));
	check_input_redirection((*line));
	check_output_redirection((*line));
	check_pipes(line, 1);
	mixed_command((*line), 1, 1);
	double_symbol((*line), ';', 1);
	check_multiline_commands((*line), 0);
	printf("validated line = |%s|\n", (*line));
}
