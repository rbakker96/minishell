/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 15:55:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/08 16:07:59 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "structs.h"

# include <stdio.h>

/*
**---------------------------ADDITIONAL FUNCTIONS-------------------------------
*/

/*
** file_one.c
*/
int		print(char *str);
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

/*
**----------------------------------PARSE---------------------------------------
*/

/*
** create_command_table.c
*/
int		parse_command(t_data *data);
void	create_command_table(t_data *data, char *line);
void	process_tokens(t_data *data, char *command, int i, int len);

/*
**----------------------------------VALIDATE_INPUT------------------------------
*/

/*
** validate_input.c
*/
int		input_validate(char *line);
int 	check_duplicated_symbols(char *line);

#endif
