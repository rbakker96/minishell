# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbakker <rbakker@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/05 14:55:09 by rbakker       #+#    #+#                  #
#    Updated: 2020/09/29 16:34:28 by roybakker     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

SOURCES			= 	main.c \
					2_supportive_functions/file_one.c \
					2_supportive_functions/file_two.c \
					2_supportive_functions/file_three.c \
					2_supportive_functions/file_four.c \
					2_supportive_functions/file_five.c \
					3_error_management/parse_error/validate_input.c \
					3_error_management/parse_error/check_functions.c \
					3_error_management/parse_error/parse_error.c \
					4_execution/cd.c \
					4_execution/echo/echo.c \
					4_execution/echo/no_quotes.c \
					4_execution/echo/double_quotes.c \
					4_execution/echo/single_quotes.c \
					4_execution/executable/create_arguments.c \
					4_execution/executable/run_executable.c \
					4_execution/output/create_fd.c \
					4_execution/output/handle_redirection_files.c \
					4_execution/env.c \
					4_execution/exit.c \
					4_execution/export.c \
					4_execution/unset.c \
					4_execution/execute_loop.c \
					4_execution/pwd.c \
					5_parse/create_command_table.c \
					5_parse/commands.c \
					5_parse/tokens.c \

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
