/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 15:55:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 15:58:32 by roybakker     ########   odam.nl         */
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

/*
**---------------------------ADDITIONAL_FUNCTIONS-------------------------------
*/

/*
** file_one.c
*/
int		print(char *str);
int		prompt(void);
void	free_split_array(char **array);

/*
** file_two.c
*/
int		get_amount_of_commands(char *line, char c);
int		get_amount_of_tokens(char *command);
int		token_id(char c);
int		begin_token(char *command, int i);
int		len_token(char *command, int start, int len, int *space);

/*
** file_three.c
*/
void	special_char(char *command, int *i, int *token);
void	dubbel_quotes(char *command, int *i, int *token);
void	single_qoutes(char *command, int *i, int *token);
void	basic_word(char *command, int *i, int *token);

/*
** file_four.c
*/
int		option(char *str);
int		redirection(char *str);
int		check_executable_path(char *command);
int		ft_isspace(int c);

/*
**-----------------------------INPUT_VALIDATION---------------------------------
*/

/*
** validate_input.c
*/
int		input_validate(char *line);
int 	check_duplicated_symbols(char *line);

/*
**----------------------------------PARSE---------------------------------------
*/

/*
** create_command_table.c
*/
int		parse_command(t_data *data);
void	create_command_table(t_data *data, char *line);
void	save_tokens(t_data *data, char *command, int i, int len);

/*
**---------------------------------EXECUTION------------------------------------
*/

/*
** execution_loop.c
*/
void	execution_loop(t_data *data, int command, int token);
void	identfy_command(t_data *data, int command, int *token);

/*
** cd.c
*/
void	execute_cd(t_data *data, int command, int *token);

/*
** echo.c
*/
void	execute_echo(t_data *data, int command, int *token);

/*
** env.c
*/
void	execute_env(t_data *data, int command, int *token);

/*
** execution.c
*/
void	execute_executable(t_data *data, int command, int *token);

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

/*
** unset.c
*/
void	execute_unset(t_data *data, int command, int *token);


#endif
