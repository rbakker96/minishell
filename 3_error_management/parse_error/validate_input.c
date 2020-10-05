/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/03 15:19:55 by qli           #+#    #+#                 */
/*   Updated: 2020/10/05 11:16:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void 	check_input_redirection(char *line, int *ret)
{
	double_symbol(line, '<', 1, ret);
	double_command(line, '<', 1, ret);
	end_of_line_command(line, '<', 1, ret);
}

void	check_output_redirection(char *line, int *ret)
{
	double_command(line, '>', 1, ret);
	end_of_line_command(line, '>', 1, ret);
}

void	check_pipes(char **line, int i, int *ret)
{
	char *str;

	double_command((*line), '|', 1, ret);
	end_of_line_command((*line), '|', 1, ret);
	while ((*line)[i] != '\0')
	{
		if((*line)[i - 1] != '\\' && (*line)[i] == '|' && (*line)[i + 1] == '|' )
		{
			str = ft_substr((*line), 0, i);
			//malloc error
			//
			free((*line));
			*line = str;
		}
		i++;
	}
}

void	check_multiline_commands(char *line, int i, int *ret)
{
	while (line[i] != '\0')
	{
		if ((token_id(line[i]) == 2 || token_id(line[i]) == 3) && i == 0)
			validate_qoute(line, &i, token_id(line[i]), ret);
		else if ((token_id(line[i]) == 2 || token_id(line[i]) == 3) && line[i - 1] != '\\')
			validate_qoute(line, &i, token_id(line[i]), ret);
		i++;
	}
}

int		input_validation(char **line)
{
	int ret;

	ret = 0;
	check_first_symbol((*line), &ret);
	check_input_redirection((*line), &ret);
	check_output_redirection((*line), &ret);
	check_pipes(line, 1, &ret);
	mixed_command((*line), 1, 1, &ret);
	double_symbol((*line), ';', 1, &ret);
	check_multiline_commands((*line), 0, &ret);
	if (ret == 0)
		printf("validated line = [%s]\n", (*line));
	return (ret);
}
