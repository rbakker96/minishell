/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation_error.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/07 14:10:52 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/21 20:13:02 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	validation_error(t_data *data, char charachter)
{
	print(data, 2, "minishell: parse error near ", 0);
	print_char(data, 2, charachter, 0);
	print_char(data, 2, '\n', 0);
	g_exit_code = 1;
	free_struct(data);
}
