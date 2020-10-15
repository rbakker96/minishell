/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 14:27:26 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/15 17:31:09 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define STDIN 0
# define READ 0
# define STDOUT 1
# define WRITE 1

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
	redirected = 9,
	succes = 10
}						t_defenitions;

/*
**---------------------------------MINISHELL------------------------------------
*/

typedef struct			s_command_table
{
	char				*command;
	char				**tokens;
	int					token_amount;
	int					**pipes;
	int					pipe_nb;
	int					pipe_index;
}						t_command_table;

typedef struct			s_data
{
	char				*input;
	char				*current_token;
	t_command_table		**commands;
	int					fd[2];
	char				**envp;
	char				**args;
	int					command_amount;
}						t_data;

#endif
