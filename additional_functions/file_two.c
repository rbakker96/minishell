/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_two.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 14:39:39 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 21:25:09 by roybakker     ########   odam.nl         */
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
		if (str[i] == '<' || str[i] == '>' || (str[i] == '>' && str[i + 1] == '>') ||str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

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

int		pipe_check(char *str)
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

char		*join(char *s1, char *s2, int i, int x)
{
	char	*joined_str;

	i = ft_strlen(s1);
	x = ft_strlen(s2);
	joined_str = malloc(sizeof(char) * (i + x + 1));
// 	CLEAR STRUCT WHEN FAIL
//
	x = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		joined_str[i] = s1[i];
		i++;
	}
	joined_str[i] = ' ';
	i++;
	while (s2[x] != '\0')
	{
		joined_str[i + x] = s2[x];
		x++;
	}
	joined_str[i + x] = '\0';
	free(s1);
	return (joined_str);
}
