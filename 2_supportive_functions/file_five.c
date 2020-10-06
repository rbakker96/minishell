/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:44:49 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/06 17:08:03 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_array_size(char **array)
{
	int 	i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}

int		redirection_check(char *str)
{
	if (!str)
		return (0);
	else if (ft_strncmp(str, "<", ft_strlen(str)) == 0)
		return (redirected);
	else if (ft_strncmp(str, ">", ft_strlen(str)) == 0)
		return (redirected);
	else if (ft_strncmp(str, ">>", ft_strlen(str)) == 0)
		return (redirected);
	return (0);
}

int		quotes_check(char *str)
{
	if (str[0] == '\"')
		return (double_quote);
	else if (str[0] == '\'')
		return (single_quote);
	else
		return (normal_char);
}

int		env_var_len(char *str, int i)
{
	int len;

	len = 0;
	while (str[i + len] != '\0' && str[i + len] != ' ' && str[i + len] != '\"')
		len++;
	return (len);
}
