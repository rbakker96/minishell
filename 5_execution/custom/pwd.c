/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/10/19 14:52:42 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_pwd(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	char	buf[PATH_MAX];
	char	*value;

	cmd++;
	value = getcwd(buf, (size_t)PATH_MAX);
	if (value == NULL)
	{
		printf("exit->code set in pwd - wrong\n");
		data->exit_code = 1; //add exit code
		get_directory_error(data);
	}
	print(data, data->iostream[1], value, 0);
	print_char(data, data->iostream[1], '\n', 0);
	printf("exit->code set in pwd\n");
	data->exit_code = 0; //add exit code
	(*tkn) = needed_tokens;
}
