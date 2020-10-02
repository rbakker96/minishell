/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 15:55:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/02 17:11:42 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include "1_supportive_lib/libft/libft.h"
# include "1_supportive_lib/gnl/get_next_line.h"
# include "structs.h"
# include <stdio.h> //to remove
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <sys/stat.h>
# include <errno.h>      /* for 'ENOENT' and 'ENOMEM' */
# include <limits.h>
# include <string.h> /* for strerror */
# include <sys/stat.h> /* for open */
# include <fcntl.h> /* for open */

/*
**---------------------------SUPPORTIVE__FUNCTIONS------------------------------
*/

/*
** file_one.c
*/
int		print(int fd, char *str);
void	print_char(int fd, char c);
int		prompt(void);
char	*get_current_directory(void);

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
**-----------------------------ERROR_MANAGEMENT---------------------------------
*/

	/*
	**--------------------------EXECUTION_ERROR---------------------------------
	*/

	/*
	** execution_error.c
	*/
void	redirection_error(t_data *data, char *filename, int i, int *token);
void	change_directory_error(t_data *data, char *filename, int i, int *token);
void	malloc_error(t_data *data, int index, char **malloced_array);
void	fork_error(t_data *data, int index);

	/*
	**----------------------------PARSE_ERROR-----------------------------------
	*/

	/*
	** parse_error.c
	*/
void	print_error(char charachter, int *ret);

	/*
	** validate_input.c
	*/
int		input_validation(char **line);
void 	check_input_redirection(char *line, int *ret);
void	check_output_redirection(char *line, int *ret);
void	check_pipes(char **line, int i, int *ret);
void	check_multiline_commands(char *line, int i, int *ret);

	/*
	** check_functions.c
	*/
void	double_symbol(char *line, char c, int i, int *ret);
void	double_command(char *line, char c, int i, int *ret);
void	mixed_command(char *line, int i, int x, int *ret);
void	end_of_line_command(char *line, char c, int i, int *ret);
void	validate_qoute(char *line, int *i, int x, int *ret);
void	check_first_symbol(char *line, int *ret);


/*
**-----------------------------MEMORY_MANAGEMENT---------------------------------
*/

/*
** free_struct.c
*/
void	free_struct(t_data *data);
void	free_array(char **array);

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
void	execute_cd(t_data *data, int command, int *token, int needed_tokens);
char	*get_argument(t_data *data, int i, int *token, int needed_tokens);
void	go_to_home(t_data *data, int i, int *token, int needed_tokens);

	/*
	**---------------------------------ECHO------------------------------------
	*/

	/*
	** echo.c
	*/
void	execute_echo(t_data *data, int i, int *token, int needed_tokens);
int		newline_option(char *value, int needed_tokens, int *token);
void	echo_variable(t_data *data, int i, int *token, int *index);
char	*get_variable(t_data *data, char *value, int index, int i, int len);

	/*
	** no_quotes.c
	*/
void	no_quotes(t_data *data, int i, int *token, int *index);
void	no_quotes_escape(t_data *data, int i, int *token, int *index);

	/*
	** single_quotes.c
	*/
void	single_quotes(t_data *data, int i, int *token, int *index);

	/*
	** double_quotes.c
	*/
void	double_quotes(t_data *data, int i, int *token, int *index);
void	double_quotes_escape(t_data *data, int i, int *token, int *index);

	/*
	**-----------------------------EXECUTABLE-----------------------------------
	*/

	/*
	** create_arguments.c
	*/
void	create_args(t_data *data, int command, int token);
int		check_args_num(t_data *data, int command, int token);

	/*
	** run_executable.c
	*/
void	execute_executable(t_data *data, int i, int *token, int needed_tokens);
void	execute_absolute_executable(t_data *data, int i, int *token, int x);
int		fork_executable(t_data *data, int i);

	/*
	**---------------------------------OUTPUT-----------------------------------
	*/

	/*
	** create_fd.c
	*/
void	create_fd(t_data *data, int i, int token, int *needed_tokens);

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
void	execute_env(t_data *data, int *token);


/*
** exit.c
*/
void	execute_exit(t_data *data, int i, int *token);

/*
** export.c
*/
void	execute_export(t_data *data, int i, int *token);

/*
** pwd.c
*/
void	execute_pwd(t_data *data, int i, int *token, int needed_tokens);

/*
** unset.c
*/
void	execute_unset(t_data *data, int i, int *token);

/*
**----------------------------------PARSE---------------------------------------
*/

/*
** create_command_table.c
*/
int		parse_command(t_data *data, char **envp);
int		save_environment_variables(t_data *data, char **envp);
int		create_command_table(t_data *data, char *line, int i);

/*
** commands.c
*/
char	**save_commands(char *line, char command_amount, int i, int index);
int		len_command(char *line, int i, int len);
int		empty_command(char *line, int i);

/*
** tokens.c
*/
void	save_tokens(t_data *data, char **array, char *command, int i, int len);
int		begin_token(char *command, int i);
int		len_token(char *command, int start, int len, int *spaces);
int		len_sentence(char *command, int start, int len, int *spaces);

#endif
