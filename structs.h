/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 14:27:26 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/24 11:32:21 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
**--------------------------------GENERAL---------------------------------------
*/

typedef enum			e_defenitions
{
	space = 0,
	meta_char = 1,
	double_quote = 2,
	single_quote = 3,
	normal_char = 4,
	piped = 5,
	input = 6,
	overwrite = 7,
	append = 8,
	redirected = 9
}						t_defenitions;

/*
**-------------------------------EXECUTION--------------------------------------
*/

typedef struct 			s_fd
{
	int					input;
	int					output;
}						t_fd;

/*
**---------------------------------PARSE----------------------------------------
*/
typedef struct 			s_command_table
{
	char				**tokens;
	int					token_amount;
	t_fd				fd;
	int 				exit_code;
}						t_command_table;

typedef struct 			s_data
{
	t_command_table 	**commands;
	char				**env;
	int					command_amount;
}						t_data;

#endif
