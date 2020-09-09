/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 14:27:26 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 12:01:11 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
**--------------------------------GENERAL---------------------------------------
*/

typedef enum			e_defenitions
{
	piped = 1,
	input = 2,
	overwrite = 3,
	append = 4
}						t_defenitions;

/*
**-------------------------------EXECUTION--------------------------------------
*/

typedef struct 			s_table_item
{
	char 				*command;
	char				*option;
	char				*operation;
	char 				*input;
	char 				*output;
}						t_table_item;

/*
**---------------------------------PARSE----------------------------------------
*/
typedef struct 			s_command_table
{
	char				**tokens;
	int					token_amount;
	int 				exit_code;
}						t_command_table;

typedef struct 			s_data
{
	t_command_table 	**commands;
	int					command_amount;
}						t_data;

#endif
