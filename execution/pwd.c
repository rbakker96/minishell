/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/09/23 15:18:51 by qli           ########   odam.nl         */
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
	check_input_redir(data, command, *token, &fd);
	if (fd == -1)
		*token = data->commands[command]->token_amount;
	check_output_redir(data, command, token, &fd);
	check_pipe(data, command, token, ptr);
	// print("child\n");
	// write_pwd(fd, ptr);
}

// if input direction file does not exist, program stops & give an error message
// can be moved earlier into the input check
void	check_input_redir(t_data *data, int command, int token, int *fd)
{
	while (token + 1 < data->commands[command]->token_amount)
	{
		if (redirection(data->commands[command]->tokens[token]) == input)
		{
			printf("%s\n", data->commands[command]->tokens[token + 1]);
			*fd = open(data->commands[command]->tokens[token + 1], O_RDONLY);
			//	PRINT ERROR MESSAGE
			//
		}
		token++;
	}
}

void	check_output_redir(t_data *data, int command, int *token, int *fd)
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

void	check_pipe(t_data *data, int command, int *token, char *ptr)
{
	if (*token < data->commands[command]->token_amount)
	{
		if (ft_strncmp(data->commands[command]->tokens[*token], "|", 1) == 0)
		{
			*token = *token + 1; //move to cat
			create_pipe(data, command, token, ptr);
		}
	}
}

void	create_pipe(t_data *data, int command, int *token, char *ptr)
{
	int	pipefd[2];
	int	pipe_ret;
	int	pid;
	char *args[] = {"/usr/bin/cat", "out2", NULL};
	char *envp[] = {NULL};
	int fd;
	int	status;
	// char buf;

	pipe_ret = pipe(pipefd);
	if (pipe_ret == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	//CLEAR STRUCT WHEN FAIL FOR BOTH -1
	//
	if (pid == 0)
	{
		close(pipefd[1]);
		*token = *token + 2;
		fd = open(data->commands[command]->tokens[*token], O_CREAT | O_WRONLY  | O_APPEND, 0664);
		dup2(pipefd[0], 0);
		dup2(fd, 1);
		printf("child\n");
		// close(pipefd[0]);
		printf("%s\n", data->commands[command]->tokens[*token - 2]);
		execve("/usr/bin/cat", args, envp);

		// while (read(pipefd[0], &buf, 1) > 0)
		// 	write(fd, &buf, 1);
		// write(fd, "\n", 1);

		// dup2(pipefd[0], 0); // cat to read from pipefd[0]
		// if (ft_strncmp(data->commands[command]->tokens[*token + 1], ">", 1) == 0)
		// {
		// 	fd = open(data->commands[command]->tokens[*token + 2], O_CREAT | O_WRONLY  | O_TRUNC, 0664);
		// 	*token = *token + 2;
		// 	dup2(fd, 1);
		// }
		// close(pipefd[0]);
		// execve(data->commands[command]->tokens[(*token)], args, envp);
	}
	else
	{
		//pwd write to the pipe
		printf("here\n");
		close(pipefd[0]);
		write(pipefd[1], ptr, ft_strlen(ptr));
		close(pipefd[1]);
		wait(&status);
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