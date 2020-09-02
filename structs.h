/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 14:27:26 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/02 15:26:21 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
**----------------------------------PARSE---------------------------------------
*/

typedef struct 			s_big
{
	char 				*command;
	char				option;
	char 				*input;
	char 				*output;
	int 				exit_code;
}						t_big;

typedef struct 			s_average
{
	char 				*command;
	char				option;
	char				*input;
	int 				exit_code;
}						t_average;

typedef struct 			s_small
{
	char 				*command;
	int 				exit_code;
}						t_small;

typedef union			u_command
{
	t_small				small;
	t_average			average;
	t_big				big;
}						t_command;

typedef struct 			s_command_table
{
	t_command 			**command;
}						t_command_table;

typedef struct 			s_data
{
	t_command_table 	**table;
}						t_data;


#endif
