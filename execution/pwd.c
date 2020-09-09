/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/09/09 16:02:07 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		execute_pwd(t_data *data, int command, int *token)
{
	char buf[PATH_MAX];
	char *ptr;

	if(data && (*token) && command)
		print(".");
	ptr = getcwd(buf, (size_t)PATH_MAX);
//	CLEAR STRUCT WHEN FAIL
//
	print(ptr);
	print("\n");
}
