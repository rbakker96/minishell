/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/09/09 11:22:10 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		execute_pwd(void)
{
	char buf[PATH_MAX];
	char *ptr;

	ptr = getcwd(buf, (size_t)PATH_MAX);
	if (ptr == NULL)
		return (-1);
	print(ptr);
	print("\n");
	return (0);
}
