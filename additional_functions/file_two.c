/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_two.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 14:39:39 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/04 13:24:39 by roybakker     ########   odam.nl         */
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

	result = ft_strncmp(str, "<", ft_strlen(str));
	if (result != 0)
		result = ft_strncmp(str, ">", ft_strlen(str));
	if (result != 0)
		result = ft_strncmp(str, ">>", ft_strlen(str));
	return (result);
}

int		split_check(char *str)
{
	int count;

	count = pipe_count(str);
	count += redirection_count(str, 0, 0);
	return (count);
}

int		pipe_count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '|')
			count++;

		i++;
	}
	return (count);
}

int		redirection_count(char *str, int input, int output)
{
	int i;
	int count;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '<')
			input++;
		else if (i != 0 && str[i] == '>' && str[i - 1] != '>' &&
						   str[i] == '>' && str[i - 1] == '>')
			output++;
		i++;
	}
	count = (input >= 2) ? (input - 1) : 0;
	count += (output >= 2) ? (output - 1) : 0;
	return (count);
}
