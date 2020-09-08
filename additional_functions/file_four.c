/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_four.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:47:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/08 17:13:29 by qli           ########   odam.nl         */
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

int		check_executable_path(char *command)
{
	int i;

	i = 0;
	while (command[i] != '\0')
	{
		if (ft_isspace(command[i]) == 1)
			i++;
		else if (command[i] == '.' || command[i] == '/')
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}

int		ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}