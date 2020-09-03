/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 14:27:26 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 21:02:02 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
**----------------------------------PARSE---------------------------------------
*/

typedef struct 			s_command_table
{
	char 				*command;
	char				*operation;
	char 				*input;
	char 				*output;
	int 				exit_code;
}						t_command_table;

typedef struct 			s_data
{
	t_command_table 	**table;
	int					size;
	int					index;
}						t_data;

#endif
