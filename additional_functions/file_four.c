/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_four.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:47:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/08 15:53:43 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		option(char *str)
{
	int result;

	result = ft_strncmp(str, "-n", 2);
	return (result);
}

int		redirection(char *str)
{
	int result;

	result = 0;
	if (!str)
		return (0);
	if (ft_strncmp(str, "|", ft_strlen(str)) == 0 )
		result = piped;
	else if (ft_strncmp(str, "<", ft_strlen(str)) == 0)
		result = input;
	else if (ft_strncmp(str, ">", ft_strlen(str)) == 0)
		result = overwrite;
	else if (ft_strncmp(str, ">>", ft_strlen(str)) == 0)
		result = append;
	return (result);
}
