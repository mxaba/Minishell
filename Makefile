# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mxaba <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/31 08:29:51 by mxaba             #+#    #+#              #
#    Updated: 2018/09/07 09:35:26 by mxaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell

FLAGS	=	gcc -Wall -Wextra -Werror

SRC	=	main.c ft_functions.c ft_cd.c ft_echo.c execute_cmd.c ft_setenv.c \
		ft_unsetenv.c

OBJ 	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:
		@make -C libft/
		@$(FLAGS) -c $(SRC)
		@$(FLAGS) -o $(NAME) $(SRC) -L libft/ -lft

clean	:
		@make clean -C libft/
		@rm -rf $(OBJ)

fclean	: 	clean
		@make fclean -C libft/
		@rm -rf $(NAME)

re	: 	fclean all

norm	:
		@echo "\033[32m  ~~~~~~--------------~~~~~\033[0m"
		@echo "\033[32m%########| 0.00% |########%\033[0m"
		@find . -name "*.c" -exec norminette {} \;
		@echo "\033[32m%########| 100%  |########%\033[0m"
		@echo "\033[32m  ~~~~++++++++++++++++~~~~~\033[0m"
