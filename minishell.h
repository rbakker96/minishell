/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 15:55:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/04 12:35:03 by qli           ########   odam.nl         */
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
int			print(char *str);
int			calculate_table_size(char **str);
int			commands_count(char **str);

/*
** file_two.c
*/
int			command_type_check(char *str);
int			option(char *str);
int			redirection(char *str);
int			pipe_check(char *str);
char		*join(char *s1, char *s2, int i, int x);

/*
**----------------------------------PARSE---------------------------------------
*/

/*
** create_command_table.c
*/
int			parse_command(t_data *data);
void		create_command_table(t_data *data, char *line);
void		basic_command(t_data *data, char *command, int index);
void		piped_command(t_data *data, char *command);

/*
** analyze_commands.c
*/
void		small_command(t_data *data, char **tokens, int index, int size);
void		big_command(t_data *data, char *command, int index);

/*
**----------------------------------VALIDATE_INPUT------------------------------
*/

/*
** validate_input.c
*/
int		input_validate(char *line);
int 	check_duplicated_symbols(char *line);

#endif
