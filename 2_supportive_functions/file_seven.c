/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_seven.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/22 14:10:21 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/22 14:11:04 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		command_check(char check_value, char charachter)
{
	if (charachter == check_value || charachter == '|' || charachter == ';' ||
		charachter == '\0')
		return (-1);
	else
		return (0);
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
