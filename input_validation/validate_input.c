/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/03 15:19:55 by qli           #+#    #+#                 */
/*   Updated: 2020/09/15 11:37:56 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void 	check_input_redirection(char *line)
{
	dubbel_symbol(line, '<', 0);
	dubbel_command(line, '<', 0);
	end_of_line_command(line, '<', 0);
}

void	check_output_redirection(char *line)
{
	dubbel_command(line, '>', 0);
	end_of_line_command(line, '>', 0);
}

void	check_pipes(char **line, int i)
{
	char *str;

	dubbel_command((*line), '|', 0);
	end_of_line_command((*line), '|', 0);
	while ((*line)[i] != '\0')
	{
		if((*line)[i] == '|' && (*line)[i + 1] == '|' )
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
		if((token_id(line[i]) == 2 || token_id(line[i]) == 3) && i == 0)
			validate_qoute(line, &i, token_id(line[i]));
		else if((token_id(line[i]) == 2 || token_id(line[i]) == 3) && line[i - 1] != '\\')
			validate_qoute(line, &i, token_id(line[i]));
		i++;
	}
}

void	input_validation(char **line)
{
	check_input_redirection((*line));
	check_output_redirection((*line));
	check_pipes(line, 0);
	mixed_command((*line), 0, 0);
	dubbel_symbol((*line), ';', 0);
	check_multiline_commands((*line), 0);
}
