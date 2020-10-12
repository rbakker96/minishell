# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbakker <rbakker@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/05 14:55:09 by rbakker       #+#    #+#                  #
<<<<<<< HEAD
#    Updated: 2020/10/12 14:01:22 by qli           ########   odam.nl          #
=======
#    Updated: 2020/10/12 13:22:46 by rbakker       ########   odam.nl          #
>>>>>>> 5b4bc518d4f7d1f43ef378889db4b41cd2d95ce3
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

SOURCES			= 	main.c \
					2_supportive_functions/file_one.c \
					2_supportive_functions/file_two.c \
					2_supportive_functions/file_three.c \
					2_supportive_functions/file_four.c \
					2_supportive_functions/file_five.c \
					2_supportive_functions/file_six.c \
					3_error_management/external_function_error.c \
					3_error_management/file_system_error.c \
					3_error_management/memory_error.c \
					3_error_management/validation_error.c \
					4_memory_management/free_struct.c \
					5_execution/cd.c \
					5_execution/echo.c \
					5_execution/executable/create_arguments.c \
					5_execution/executable/run_executable.c \
					5_execution/shell_expansions/expand_functions.c \
					5_execution/shell_expansions/len_calculations.c \
					5_execution/shell_expansions/shell_expansions.c \
					5_execution/arguments_list.c \
					5_execution/redirections.c \
					5_execution/env.c \
					5_execution/exit.c \
					5_execution/export.c \
					5_execution/unset.c \
					5_execution/execute_loop.c \
					5_execution/pwd.c \
					5_execution/pipe/create_pipe_fd.c \
					5_execution/pipe/set_pipe_fd.c \
					5_execution/pipe/child_pipe_fd_setup.c \
					5_execution/pipe/parent_pipe_fd_setup.c \
					6_parse/create_command_table.c \
					6_parse/commands.c \
					6_parse/tokens.c \
					7_input_validation/input_validation.c \
					7_input_validation/validate_quotes.c \
					7_input_validation/validate_redirections.c

OBJECTS 		=	${SOURCES:%.c=%.o}

INLCUDES 		= 	-L1_supportive_lib/gnl -lgnl -L1_supportive_lib/libft -lft
EXTERNAL_LIBS	=	1_supportive_lib/libft/libft.a 1_supportive_lib/gnl/libgnl.a
LIBFT			=	1_supportive_lib/libft
GNL				=	1_supportive_lib/gnl

FLAGS 			=	-Wall -Wextra -Werror
COMPILE			=	gcc
LIB				=	ar rc

GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

UNAME_S			:=	$(shell uname -s)

all: $(NAME)

ifeq ($(UNAME_S),Linux)
$(NAME): $(OBJECTS)
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(WHITE)GET NEXT LINE			$(WHITE)"
	@make -C $(GNL)
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(WHITE)LIBFT			$(WHITE)"
	@make -C $(LIBFT)
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(FLAGS) $(INLCUDES) $(OBJECTS) $(EXTERNAL_LIBS) -o $(NAME)
	@echo "Executable				./minishell"
	@echo "$(GREEN)----------------------------------------------------"
endif

ifeq ($(UNAME_S),Darwin)
$(NAME): $(OBJECTS)
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(WHITE)GET NEXT LINE			$(WHITE)"
	@make -C $(GNL)
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(WHITE)LIBFT			$(WHITE)"
	@make -C $(LIBFT)
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(FLAGS) $(INLCUDES) -o $(NAME) $(OBJECTS)
	@echo "Executable				./minishell"
	@echo "$(GREEN)----------------------------------------------------"
endif

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(FLAGS) -I$(LIBFT) -I$(GNL) -c -o $@ $<

clean:
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)REMOVED O-FILES GNL"
	@echo "$(RED)----------------------------------------------------"
	@make clean -C $(GNL)
	@echo "$(WHITE)REMOVED O-FILES LIBFT"
	@echo "$(RED)----------------------------------------------------"
	@make clean -C $(LIBFT)
	@echo "$(WHITE)REMOVED O-FILES MINISHELL"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)DELETE LIBGNL.A"
	@echo "$(RED)----------------------------------------------------"
	@make fclean -C $(GNL)
	@echo "$(WHITE)DELETE LIBFT.A"
	@echo "$(RED)----------------------------------------------------"
	@make fclean -C $(LIBFT)
	@echo "$(WHITE)DELETE ./MINISHELL"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
