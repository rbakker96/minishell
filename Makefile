# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbakker <rbakker@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/05 14:55:09 by rbakker       #+#    #+#                  #
#    Updated: 2020/09/28 18:03:38 by roybakker     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

SOURCES			= 	main.c \
					additional_functions/file_one.c \
					additional_functions/file_two.c \
					additional_functions/file_three.c \
					additional_functions/file_four.c \
					additional_functions/file_five.c \
					input_validation/validate_input.c \
					input_validation/check_functions.c \
					parse/create_command_table.c \
					parse/commands.c \
					parse/tokens.c \
					execution/cd.c \
					execution/echo/echo.c \
					execution/echo/no_quotes.c \
					execution/echo/double_quotes.c \
					execution/echo/single_quotes.c \
					execution/executable/create_arguments.c \
					execution/executable/run_executable.c \
					execution/output/create_fd.c \
					execution/output/handle_redirection_files.c \
					execution/env.c \
					execution/exit.c \
					execution/export.c \
					execution/unset.c \
					execution/execute_loop.c \
					execution/pwd.c \
					error_handeling/parse_error.c

OBJECTS 		=	${SOURCES:%.c=%.o}

INLCUDES 		=  -Lgnl -lgnl -Llibft -lft
FLAGS 			=	-Wall -Wextra -Werror
COMPILE			=	gcc
LIB				=	ar rc
EXTERNAL_LIBS	=	libft/libft.a gnl/libgnl.a

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
	@make -C gnl
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(WHITE)LIBFT			$(WHITE)"
	@make -C libft
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
	@make -C gnl
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(WHITE)LIBFT			$(WHITE)"
	@make -C libft
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(FLAGS) $(INLCUDES) -o $(NAME) $(OBJECTS)
	@echo "Executable				./minishell"
	@echo "$(GREEN)----------------------------------------------------"
endif

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(FLAGS) -Ilibft -Ignl -c -o $@ $<

clean:
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)REMOVED O-FILES GNL"
	@echo "$(RED)----------------------------------------------------"
	@make clean -C gnl
	@echo "$(WHITE)REMOVED O-FILES LIBFT"
	@echo "$(RED)----------------------------------------------------"
	@make clean -C libft
	@echo "$(WHITE)REMOVED O-FILES MINISHELL"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)DELETE LIBGNL.A"
	@echo "$(RED)----------------------------------------------------"
	@make fclean -C gnl
	@echo "$(WHITE)DELETE LIBFT.A"
	@echo "$(RED)----------------------------------------------------"
	@make fclean -C libft
	@echo "$(WHITE)DELETE ./MINISHELL"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
