# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbakker <rbakker@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/05 14:55:09 by rbakker       #+#    #+#                  #
#    Updated: 2020/09/03 15:23:49 by qli           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

SOURCES			= 	main.c \
					parse/create_command_table.c \
					parse/analyze_commands.c \
					additional_functions/file_one.c \
					additional_functions/file_two.c \
					validate_input/validate_input.c

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
	@echo "$(WHITE)----------------------------------------------------"
	@echo "$(WHITE)MINISHELL			$(WHITE)"
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(FLAGS) -Ilibft -Ignl -c -o $@ $<

clean:
	@echo "$(WHITE)Working on gnl..."
	@make clean -C gnl
	@echo "$(WHITE)Working on libft..."
	@make clean -C libft
	@echo "$(WHITE)Working on minishell..."
	@echo "$(RED)DELETING OBJECTFILES"
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@echo "$(WHITE)Working on gnl..."
	@make fclean -C gnl
	@echo "$(WHITE)Working on libft...	"
	@make fclean -C libft
	@echo "$(WHITE)Working on minishell...	"
	@echo "$(RED)DELETING EXECUTABLE"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
