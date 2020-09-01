/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:34:02 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/29 11:46:09 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		result_check(const char *str, int i, int pos_neg)
{
	long int overflow_check;
	long int result;

	overflow_check = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (overflow_check <= result)
		{
			overflow_check = result;
			result = result * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			if (pos_neg == -1)
				return (0);
			else
				return (1);
		}
	}
	return (result * pos_neg);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			pos_neg;
	long int	result;

	i = 0;
	pos_neg = 1;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-' && str[i + 1] != '+')
	{
		pos_neg = -1;
		i++;
	}
	result = result_check(str, i, pos_neg);
	return (result);
}
