/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/09/22 17:05:33 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_pwd(t_data *data, int command, int *token)
{
	char 	buf[PATH_MAX];
	char 	*ptr;
	int		fd;

	fd = 0;
	*token = *token + 1;
	ptr = getcwd(buf, (size_t)PATH_MAX);
//	CLEAR STRUCT WHEN FAIL
//
	check_redirection(data, command, token, &fd);
	check_pipe(data, command, token, ptr);
	write_pwd(fd, ptr);
}

void	check_redirection(t_data *data, int command, int *token, int *fd)
{
	if (*token + 2 <= data->commands[command]->token_amount)
	{
		if (redirection(data->commands[command]->tokens[*token]) == overwrite)
		{
			*fd = open(data->commands[command]->tokens[*token + 1], O_CREAT | O_WRONLY  | O_TRUNC, 0664);
		//	CLEAR STRUCT WHEN FAIL
		//
			*token = *token + 2;
		}
		else if (redirection(data->commands[command]->tokens[*token]) == append)
		{
			*fd = open(data->commands[command]->tokens[*token + 1], O_CREAT | O_WRONLY  | O_APPEND, 0664);
		//	CLEAR STRUCT WHEN FAIL
		//
			*token = *token + 2;
		}
	}
}

// Potential to expand the print function to allow for fd
void	write_pwd(int fd, char *ptr)
{
	write(fd, ptr, ft_strlen(ptr));
	write(fd, "\n", 1);
	//	CLEAR STRUCT WHEN FAIL
	//
}

void	check_pipe(t_data *data, int command, int *token, char *ptr)
{
	if (*token < data->commands[command]->token_amount)
	{
		if (ft_strncmp(data->commands[command]->tokens[*token], "|", 1) == 0)
		{
			create_pipe(data, command, token, ptr);
		}
	}
}

void	create_pipe(t_data *data, int command, int *token, char *ptr)
{
	int	pipefd[2];
	int	pipe_ret;

	if (data && command && (*token))
		print(".");
	pipe_ret = pipe(pipefd);
	//	CLEAR STRUCT WHEN FAIL
	//
	if (pipe_ret == -1)
		exit(-1);
	printf("pipefd[0] is %d\n", pipefd[0]);
	printf("pipefd[1] is %d\n", pipefd[1]);
	printf("pwd is %s\n", ptr);
	//pwd write to the pipe
	// close(pipefd[0]);
	// write(pipefd[1], ptr, ft_strlen(ptr));
	// close(pipefd[1]);
	*token = *token + 1;
}
