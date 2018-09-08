# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mxaba <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/31 10:01:56 by mxaba             #+#    #+#              #
#    Updated: 2018/09/07 09:21:01 by mxaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRC1 = ft_strlen.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_strcpy.c \
	   ft_strncpy.c ft_strdup.c ft_strcat.c ft_strstr.c ft_strchr.c \
	   ft_strrchr.c ft_strnstr.c ft_strncat.c ft_strlcat.c \
	   ft_tolower.c ft_toupper.c ft_memset.c ft_memcpy.c ft_memccpy.c \

SRC2 = ft_memmove.c ft_memchr.c ft_memcmp.c ft_bzero.c ft_isprint.c \
	   ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c \
	   ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_strclr.c \
	   ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strequ.c \

SRC3 = ft_strnequ.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_strrev.c ft_int_len.c ft_striter.c \
	   ft_striteri.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strtrim.c \
	   ft_itoa.c ft_abs.c ft_putnbr_fd.c ft_strsplit.c get_next_line.c \

SRC4 = ft_freearray.c ft_split.c ft_startwith.c

SRC = $(SRC1) $(SRC2) $(SRC3) $(SRC4)
 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "Compiling $(NAME) ..."
	@gcc $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "Removing object files ..."
	@rm -f $(OBJ)

fclean: clean
	@echo "Removing $(NAME) ..."
	@rm -f $(NAME)

re: fclean all

norm:
	@echo "\033[32m###############  0.8%   ###################\033[0m"
	@norminette $(SRC1)
	@echo "\033[32m###############  35.6%  ###################\033[0m"
	@norminette $(SRC2)
	@echo "\033[32m###############  62.9%  ###################\033[0m"
	@norminette $(SRC3) $(SRC4)
	@echo "\033[32m###############  94.8%  ###################\033[0m"
	@norminette $(HEADER)
	@echo "\033[32m###############  100%   ###################\033[0m"

fresh:
	@echo "Clear ..."
	@clear
