/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/21 16:45:15 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*g_dir_path = NULL;

int		main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.exit_code = 0;
	if (argc != 1 || !argv)
		return (-1);
	handle_all_signal(&data);
	g_dir_path = get_current_directory(&data); // need to deal with free & cd change
	while (1)
	{
		prompt(&data);
		if (parse_command(&data, envp) != -1)
			execution_loop(&data, 0, 0);
		// printf("data.exit_code is %d\n", data.exit_code);
	}
	return (0);
}
