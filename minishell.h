/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 15:55:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/12 13:37:31 by qli           ########   odam.nl         */
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
# include <sys/stat.h>
# include <errno.h>      /* for 'ENOENT' and 'ENOMEM' */
# include <limits.h>
# include <string.h> /* for strerror */
# include <sys/stat.h> /* for open */
# include <fcntl.h> /* for open */

/*
**--FOLDER-------------------2_SUPPORTIVE__FUNCTIONS------------------------------
*/

/*
** file_one.c
*/
void	print(t_data *data, int fd, char *str, char *malloced_str);
void	print_char(t_data *data, int fd, char c, char *malloced_str);
int		prompt(t_data *data);
char	*get_current_directory(t_data *data);

/*
** file_two.c
*/
int		get_amount_of_commands(char *line, int i);
int		get_amount_of_tokens(char *command, int cmd, int tkn);
int		char_type(char c);

/*
** file_three.c
*/
void	meta_token(char *command, int *cmd, int *tkn);
void	quoted_sentence(char *command, int *cmd, int x);
void	normal_token(char *command, int *cmd, int *tkn);

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
int		env_var_len(char *str, int i);
int		command_check(char check_value, char charachter);
int		pipe_check(char **array, int i);

/*
**--FOLDER---------------------3_ERROR_MANAGEMENT---------------------------------
*/

/*
** external_function_error.c
*/
void	fork_error(t_data *data, int cmd);
void	write_error(t_data *data, char *malloced_str);

/*
** file_system_error.c
*/
void	redirection_error(t_data *data, char *filename, int *ret);
void	change_directory_error(t_data *data, char *filename, int i, int *tkn);
void	get_directory_error(t_data *data);

/*
** memory_error.c
*/
void	malloc_error(t_data *data, int cmd, char **malloced_array);

/*
** validation_error.c
*/
void	validation_error(t_data *data, char charachter);

/*
**--FOLDER---------------------4_MEMORY_MANAGEMENT--------------------------------
*/

/*
** free_struct.c
*/
void	free_struct(t_data *data);
void	free_array(char **array);

/*
**--FOLDER-------------------------5_EXECUTION------------------------------------
*/

/*
**--SUB_FOLDER-----------------------EXECUTABLE-----------------------------------
*/

/*
** create_arguments.c
*/
void	create_args(t_data *data, int cmd, int tkn);
int		check_args_num(t_data *data, int cmd, int tkn);

/*
** run_executable.c
*/
void	execute_executable(t_data *data, int cmd, int *tkn, int needed_tokens);
void	execute_absolute_executable(t_data *data, int cmd, int *tkn, int x);
int		fork_executable(t_data *data, int cmd, int tkn);

/*
**--SUB_FOLDER-----------------------PIPE-----------------------------------------
*/

/*
** create_pipe_fd.c
*/
void	create_pipe_fd(t_data *data, int cmd);
void	calculate_pipe_num(t_data *data, int cmd);
void	malloc_pipe_fd(t_data *data, int cmd);

/*
** create_pipe_fd.c
*/
void	set_child_pipe_fds(t_data *data, int cmd, int tkn);
int		check_token_pipe_pos(t_data *data, int cmd, int tkn);
void	set_parent_pipe_fds(t_data *data, int cmd, int tkn);

/*
** child_pipe_fd_setup.c
*/
void	child_first_pipe_setup(t_data *data, int token_pos);
void	child_between_pipe_setup(t_data *data, int token_pos);
void	child_last_pipe_setup(t_data *data, int token_pos);

/*
** parent_pipe_fd_setup.c
*/
void	parent_first_pipe_setup(t_data *data, int token_pos);
void	parent_last_pipe_setup(t_data *data, int token_pos);
void	parent_between_pipe_setup(t_data *data, int token_pos);


/*
**--SUB_FOLDER-------------------SHELL_EXPANSIONS---------------------------------
*/

/*
** expand_functions.c
*/
void	single_quotes(t_data *data, char **new_token, int *i, int *x);
void	double_quotes(t_data *data, char **new_token, int *i, int *x);
void	escape_double_quotes(t_data *data, char **new_token, int *i, int *x);
void	env_variable(t_data *data, char **new_token, int *i, int *x);
void	save_env_variable(char *variable, char **new_token, int *x);

/*
** len_calculations.c
*/
void	single_quotes_len(char *token, int *i, int *len);
void	double_quotes_len(t_data *data, char *token, int *i, int *len);
int		escape_len_double_quotes(char *token, int *i, int len);
int		env_variable_len(t_data *data, char *token, int *i, int len);

/*
** shell_expansions.c
*/
void	shell_expansions(t_data *data, int i, int tkn);
int		expansion_len(t_data *data, int i, int len);
void	expand_token(t_data *data, char **new_token, int i, int x);

/*
** ------------------------------------
*/

/*
** arguments_list.c
*/
void	update_arguments_list(t_data *data, int cmd, int tkn, int x);
int		save_list_element(char *current_token, char **saved_token, int *tkn,
																		int *x);
int		count_usable_tokens(t_data *data, int cmd, int tkn);

/*
** cd.c
*/
void	execute_cd(t_data *data, int cmd, int *tkn, int needed_tokens);
char	*get_argument(t_data *data, int cmd, int *tkn, int needed_tokens);
void	go_to_home(t_data *data, int cmd, int *tkn, int needed_tokens);

/*
** echo.c
*/
void	execute_echo(t_data *data, int cmd, int *tkn, int needed_tokens);

/*
** env.c
*/
void	execute_env(t_data *data, int *tkn);

/*
** execution_loop.c
*/
void	execution_loop(t_data *data, int cmd, int tkn);
void	execute_command(t_data *data, int cmd, int *tkn, char *value);

/*
** exit.c
*/
void	execute_exit(t_data *data, int cmd, int *tkn);

/*
** export.c
*/
void	execute_export(t_data *data, int cmd, int *tkn);

/*
** pwd.c
*/
void	execute_pwd(t_data *data, int cmd, int *tkn, int needed_tokens);

/*
** redirections.c
*/
int		redirections(t_data *data, int cmd, int tkn);
int		append_file(t_data *data, int cmd, int *tkn, int *ret);
int		overwrite_file(t_data *data, int cmd, int *tkn, int *ret);
int		input_file(t_data *data, int cmd, int *tkn, int *ret);

/*
** unset.c
*/
void	execute_unset(t_data *data, int cmd, int *tkn);

/*
**--FOLDER--------------------------6_PARSE---------------------------------------
*/

/*
** commands.c
*/
char	**save_commands(char *line, char command_amount, int i, int index);
int		len_command(char *line, int i, int len);
int		check_for_empty_command(char *line, int i);

/*
** create_command_table.c
*/
int		parse_command(t_data *data, char **envp);
int		save_environment_variables(t_data *data, char **envp);
int		create_command_table(t_data *data, char *line, int cmd);
int		save_single_command(t_data *data, char **commands, int cmd);

/*
** tokens.c
*/
void	save_tokens(t_data *data, char **array, char *command, int cmd, int len);
int		begin_token(char *command, int cmd);
int		len_token(char *command, int start, int len, int *spaces);
void	meta_char_len(char *command, int start, int *len, int *current_char);
void	non_quoted_len(char *command, int start, int *len, int *current_char);
void	quoted_len(char *command, int start, int *len, int *current_char);

/*
**--FOLDER---------------------7_INPUT_VALIDATION---------------------------------
*/

/*
** input_validation.c
*/
void	input_validation(t_data *data);
int		validate_command_seperators(t_data *data, char *charachter);
int		validate_end_of_line_command(t_data *data, char *charachter, int len);
int		validate_start_of_line_command(t_data *data, char *charachter);

/*
** validate_quote.c
*/
int		validate_single_quotes(t_data *data, char *charachter);
int		validate_double_quotes(t_data *data, char *charachter);

/*
** validate_redirections.c
*/
int		validate_input_redirection(t_data *data, char *charachter);
int		validate_output_redirection(t_data *data, char *charachter);
int		validate_pipes(t_data *data, char *charachter);
int		replace_double_pipes(t_data *data);
void	reduce_input_str(t_data *data, int reduction, int *i);

#endif
