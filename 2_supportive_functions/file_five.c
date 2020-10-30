/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 16:44:49 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/30 10:44:10 by roybakker     ########   odam.nl         */
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

int		custom_cmd(t_data *data, int cmd, int tkn)
{
	char *value;

	value = data->commands[cmd]->tokens[tkn];
	if (compare_command("echo", value, 4) == 0 ||
		compare_command("cd", value, 2) == 0 ||
		compare_command("pwd", value, 3) == 0 ||
		compare_command("export", value, 6) == 0 ||
		compare_command("unset", value, 5) == 0 ||
		compare_command("env", value, 3) == 0 ||
		compare_command("exit", value, 4) == 0)
		return (1);
	else
		return (0);
}
