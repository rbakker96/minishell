/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation_error.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/07 14:10:52 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/22 20:59:32 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	validation_error(t_data *data, char character, int exit_code)
{
	g_exit_code = exit_code;
	print(data, 2, "minishell: syntax error near unexpected token `", 0);
	print_char(data, 2, character, 0);
	print(data, 2, "'\n", 0);
	//free_struct(data); --> this can give seg fault when running multiple echo > commands
}
