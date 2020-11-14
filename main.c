/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/28 11:57:58 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1 || !argv)
	{
	    /*
	     * Anatoliy:
	     * This message can be misleading to the user. What if they don't run it from CWD?
	     * 'is needed' for what?
	     * I'd rephrase to something like "Minishell does not take any arguments".
	     */
		print(&data, 2, "only ./minishell is needed\n", 0);
		return (-1);
	}
	initialize(&data);
	signal_handler();
	while (1)
	{
		if (g_exit_code == -1)
		{
			clear_memory(&data);
			exit(1);
		}
		prompt(&data);
		if (parse_command(&data, envp) != -1)
		    /*
		     * Anatoliy:
		     * I couldn't find any other calls to this function in the codebase, so
		     * it's not clear what cmd and tkn arguments are for.
		     */
			execution_loop(&data, 0, 0);
	}
	/*
	 * Anatoliy:
	 * No cleanup here?
	 *
	 * Btw, this code is unreachable.
	 */
	return (0);
}
