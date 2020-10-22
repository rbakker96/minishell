/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 10:55:17 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/22 14:31:21 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		cpy(char **buf, char *s1)
{
	int		size;
	char	*ptr;
	int		i;

	i = 0;
	size = 0;
	while (s1[size] != '\0')
		size++;
	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (-1); // needs to confirm
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	*buf = ptr;
	return (1);
}

int		join_free(char **s1, char *s2, int i, int x)
{
	char	*joined_str;

	while ((*s1)[i] != '\0')
		i++;
	while (s2[x] != '\0')
		x++;
	joined_str = malloc(sizeof(char) * (i + x + 1));
	if (!joined_str)
		return (cleanup(s1));
	x = 0;
	i = 0;
	while ((*s1)[i] != '\0')
	{
		joined_str[i] = (*s1)[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		joined_str[i + x] = s2[x];
		x++;
	}
	joined_str[i + x] = '\0';
	free(*s1);
	*s1 = joined_str;
	return (1);
}

int		line_break(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		cleanup(char **string1)
{
	free(*string1);
	*string1 = 0;
	return (-1); // needs to confirm
}
