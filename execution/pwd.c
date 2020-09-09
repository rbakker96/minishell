/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/09/09 15:12:51 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		execute_pwd(t_data *data, int command, int *token)
{
	char buf[PATH_MAX];
	char *ptr;

	ptr = getcwd(buf, (size_t)PATH_MAX);
//	CLEAR STRUCT WHEN FAIL
//
	print(ptr);
	print("\n");
	return ;
}
