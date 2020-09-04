/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 12:50:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/04 12:50:51 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
