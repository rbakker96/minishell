/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 14:27:26 by roybakker     #+#    #+#                 */
/*   Updated: 2020/11/02 14:33:30 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define STDIN 0
# define READ 0
# define STDOUT 1
# define WRITE 1

/*
 * Anatoliy:
 * Whenever you find yourself delimiting files with comments into sections,
 * it's usually a sign that you need to put those sections in separate files.
 *
 * (Same with many other things btw. If you can mark a section of a function
 * with comments, it's often a good idea to extract that section into a separate
 * function)
 */
/*
**--------------------------------GENERAL---------------------------------------
*/

/*
 * Anatoliy:
 * Why did you choose to store some data in an instance of t_data, and some as global
 * variables?
 *
 * (Speaking of global variables, you should avoid them at all cost as they couple your
 * code).
 */
extern	int				g_exit_code;
extern	char			*g_dir_path;
extern	int				g_pid;

typedef enum			e_defenitions
{
	unused = -2,
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
	succes = 10,
	save = 11
}						t_defenitions;

/*
**---------------------------------MINISHELL------------------------------------
*/

typedef struct			s_command_table
{
	char				**tokens;
	int					token_nb;
	int					**pipes;
	int					pipe_nb;
	int					pipe_pos;
}						t_command_table;

/*
 * Anatoliy:
 * This is a very unfortunate name for a structure. For someone reading your code
 * it's totally impossible to deduct what it represents from the type name.
 *
 * Even looking at the content of this structure it's not clear what it represents.
 * Feels like you're trying to use it to store all the state in the universe and make it
 * available to all your units. This is bad from design point of view, because again it
 * adds a lot of coupling into your system. Everything now depends of everything.
 */
typedef struct			s_data
{
	int					iostream[2];
	char				*input;
	char				**envp;
	char				**args;
	t_command_table		**commands;
	int					command_nb;
	char				*current_token;
	int					used_tokens;
}						t_data;

#endif
