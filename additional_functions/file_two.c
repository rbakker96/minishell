/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_two.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 14:39:39 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 15:56:35 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		command_type_check(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '<' || str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

int		option_check(char *str)
{
	int result;

	result = ft_strncmp(str, "-n", ft_strlen(str));
	return (result);
}

int		redirection_check(char *str)
{
	int result;

	result = ft_strncmp(str, "<", ft_strlen(str));
	if (result != 0)
		result = ft_strncmp(str, ">", ft_strlen(str));
	if (result != 0)
		result = ft_strncmp(str, ">>", ft_strlen(str));
	return (result);
}
