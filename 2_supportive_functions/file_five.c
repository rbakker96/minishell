/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 16:44:49 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/28 13:53:58 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_array_size(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i] != 0)
		i++;
	return (i);
}

int		get_command_table_size(t_command_table **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i] != 0)
		i++;
	return (i);
}

int		token_var_len(char *str, int i)
{
	int len;

	len = 0;
	while (ft_isalpha(str[i + len]) == 1 || str[i + len] == '?' ||
			str[i + len] == '_' || ft_isdigit(str[i + len]) == 1)
		len++;
	return (len);
}
