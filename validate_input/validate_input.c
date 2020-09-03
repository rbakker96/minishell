/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/03 15:19:55 by qli           #+#    #+#                 */
/*   Updated: 2020/09/03 16:09:34 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int 	check_duplicated_symbols(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == ';' && line[i + 1] == ';') || \
		(line[i] == '|' && line[i + 1] == '|' && line[i + 2] == '|'))
		{
			print("duplicatd symbols\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int		input_validate(char *line)
{
	if(check_duplicated_symbols(line) == -1)
		return(-1);	
	return (0);
}