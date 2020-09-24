/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 15:55:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/24 13:56:57 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "structs.h"
# include <stdio.h> //to remove
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>      /* for 'ENOENT' and 'ENOMEM' */
# include <limits.h>
# include <string.h> /* for strerror */
# include <sys/stat.h> /* for open */
# include <fcntl.h> /* for open */

/*
**---------------------------ADDITIONAL_FUNCTIONS-------------------------------
*/

/*
** file_one.c
*/
int		print(int fd, char *str);
int		prompt(void);
char	*get_current_directory(void);
void	free_array(char **array);

/*
** file_two.c
*/
int		get_amount_of_commands(char *line, int i);
int		get_amount_of_tokens(char *command, int i, int token);
int		token_id(char c);

/*
** file_three.c
*/
void	special_char(char *command, int *i, int *token);
void	quoted_sentence(char *command, int *i, int x);
void	basic_word(char *command, int *i, int *token);
int		quotes_count(char *command, int i, int x);

/*
** file_four.c
*/
int		option(char *str);
int		check_relative_path(char *command);
int		ft_isspace(int c);
char	*find_path(t_data *data);
int		redirection(char *str);

/*
** file_five.c
*/
int		get_array_size(char **array);
int		redirection_check(char *str);
int		quotes_check(char *str);

/*
**-----------------------------INPUT_VALIDATION---------------------------------
*/

/*
** validate_input.c
*/
void	input_validation(char **line);
void 	check_input_redirection(char *line);
void	check_output_redirection(char *line);
void	check_pipes(char **line, int i);
void	check_multiline_commands(char *line, int i);

/*
** check_functions.c
*/
void	double_symbol(char *line, char c, int i);
void	double_command(char *line, char c, int i);
void	mixed_command(char *line, int i, int x);
void	end_of_line_command(char *line, char c, int i);
void	validate_qoute(char *line, int *i, int x);
void	check_first_symbol(char *line);

/*
**------------------------------ERROR_HANDELING---------------------------------
*/

/*
** parse_error.c
*/
void	parse_error(char charachter);

/*
**----------------------------------PARSE---------------------------------------
*/

/*
** create_command_table.c
*/
int		parse_command(t_data *data);
void	create_command_table(t_data *data, char *line);

/*
** commands.c
*/
char	**save_commands(char *line, char command_amount, int i, int index);
int		len_command(char *line, int i, int len);
int		empty_command(char *line, int i);

/*
** tokens.c
*/
void	save_tokens(t_data *data, char *command, int i, int len);
int		begin_token(char *command, int i);
int		len_token(char *command, int start, int len, int *spaces);
int		len_sentence(char *command, int start, int len, int *spaces);

/*
**---------------------------------EXECUTION------------------------------------
*/

/*
** execution_loop.c
*/
void	execution_loop(t_data *data, int command, int token);
void	identfy_command(t_data *data, int i, int *token, char *value);

/*
** cd.c
*/
void	execute_cd(t_data *data, int command, int *token);
void	go_to_home(t_data *data);

	/*
	**---------------------------------ECHO------------------------------------
	*/

	/*
	** echo.c
	*/
void	execute_echo(t_data *data, int command, int *token, int token_amount);
int		newline_option(char *value, int token_amount, int *token);

	/*
	** no_quotes.c
	*/
void	no_quotes(t_data *data, int command, int *token);

	/*
	** single_quotes.c
	*/
void	single_quotes(t_data *data, int i, int *token);

	/*
	** double_quotes.c
	*/
void	double_quotes(t_data *data, int i, int *token);


	/*
	**---------------------------------OUTPUT-----------------------------------
	*/

	/*
	** create_fd.c
	*/
int		argument_count(t_data *data, int i, int token, int *token_amount);
t_fd		create_fd(t_data *data, int i, int token, int *token_amount);

	/*
	** handle_redirection_files.c
	*/
int		append_file(t_data *data, int i, int *token);
int		overwrite_file(t_data *data, int i, int *token);
int		input_file(t_data *data, int i, int *token);

	/*
	** create_pipe.c
	*/


/*
** env.c
*/
void	execute_env(t_data *data, int command, int *token);

/*
** executable.c
*/
void	execute_executable(t_data *data, int command, int *token);
void	relative_path(t_data *data, int command, int *token);
void	absolute_path(t_data *data, int command, int *token);
void	search_path(t_data *data, int command, int *token, char *path_array);

/*
** exit.c
*/
void	execute_exit(t_data *data, int command, int *token);

/*
** export.c
*/
void	execute_export(t_data *data, int command, int *token);

/*
** pwd.c
*/
void	execute_pwd(t_data *data, int command, int *token);
void	check_output_redir(t_data *data, int command, int *token, int *fd);
void	write_pwd(int fd, char *ptr);
void	check_pipe(t_data *data, int command, int *token, char *ptr);
void	create_pipe(t_data *data, int command, int *token, char *ptr);
void	check_input_redir(t_data *data, int command, int token, int *fd);

/*
** unset.c
*/
void	execute_unset(t_data *data, int command, int *token);


#endif
