/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_eight.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 20:54:07 by qli           #+#    #+#                 */
/*   Updated: 2020/11/02 16:30:07 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export_output(t_data *data, int array_size, int i, int j)
{
	char	*tmp;
	char	*printed;

	tmp = NULL;
	printed = data->envp[find_smallest_envp(data, array_size)];
	while (j < array_size - 1)
	{
		i = 0;
		while (i < array_size)
		{
			if (ft_strncmp(printed, data->envp[i], ft_strlen(printed)) < 0)
			{
				if (tmp == NULL || \
					ft_strncmp(tmp, data->envp[i], ft_strlen(tmp)) > 0)
					tmp = data->envp[i];
			}
			i++;
		}
		if (tmp != NULL)
			print_envp_line(data, tmp);
		printed = tmp;
		tmp = NULL;
		j++;
	}
}

int		find_smallest_envp(t_data *data, int array_size)
{
	int		i;
	int		smallest_pos;
	char	*line;

	i = 0;
	smallest_pos = 0;
	line = data->envp[0];
	while (i < array_size - 1)
	{
		if (ft_strncmp(line, data->envp[i], ft_strlen(line)) > 0)
		{
			line = data->envp[i];
			smallest_pos = i;
		}
		i++;
	}
	print_envp_line(data, line);
	return (smallest_pos);
}

void	print_envp_line(t_data *data, char *line)
{
	int		i;

	i = 0;
	print(data, data->iostream[WRITE], "declare -x ", 0);
	while (line[i] != '\0')
	{
		if (line[i] == '=')
		{
			print(data, data->iostream[WRITE], "=\"", 0);
			i++;
		}
		if (line[i] == '\\')
			print_char(data, data->iostream[WRITE], line[i], 0);
		print_char(data, data->iostream[WRITE], line[i], 0);
		i++;
	}
	print(data, data->iostream[WRITE], "\"\n", 0);
}
