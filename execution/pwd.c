/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/09/10 17:38:53 by qli           ########   odam.nl         */
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
	*token = *token + 1;

}
