# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 17:50:17 by fmanetti          #+#    #+#              #
#    Updated: 2020/06/22 13:23:41 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = srcs/ft_memset.c \
		srcs/ft_bzero.c \
		srcs/ft_memcpy.c \
		srcs/ft_memccpy.c \
		srcs/ft_memmove.c \
		srcs/ft_memalloc.c \
		srcs/ft_memdel.c \
		srcs/ft_memchr.c \
		srcs/ft_memcmp.c \
		srcs/ft_strlen.c \
		srcs/ft_isalpha.c \
		srcs/ft_isdigit.c \
		srcs/ft_isalnum.c \
		srcs/ft_isascii.c \
		srcs/ft_isprint.c \
		srcs/ft_isspace.c \
		srcs/ft_toupper.c \
		srcs/ft_tolower.c \
		srcs/ft_strchr.c \
		srcs/ft_strrchr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strncmp.c \
		srcs/ft_strcpy.c \
		srcs/ft_strncpy.c \
		srcs/ft_strlcpy.c \
		srcs/ft_strcat.c \
		srcs/ft_strncat.c \
		srcs/ft_strlcat.c \
		srcs/ft_strnstr.c \
		srcs/ft_atoi.c \
		srcs/ft_atof.c \
		srcs/ft_calloc.c \
		srcs/ft_strdup.c \
		srcs/ft_substr.c \
		srcs/ft_strjoin.c \
		srcs/ft_strtrim.c \
		srcs/ft_split.c \
		srcs/ft_itoa.c \
		srcs/ft_strmapi.c \
		srcs/ft_putchar.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putstr.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_putnbr.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_swap.c \
		srcs/ft_swap_f.c \
		srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c

BONUS = srcs/ft_lstnew.c \
		srcs/ft_lstadd_front.c \
		srcs/ft_lstsize.c \
		srcs/ft_lstlast.c \
		srcs/ft_lstadd_back.c \
		srcs/ft_lstdelone.c \
		srcs/ft_lstclear.c \
		srcs/ft_lstiter.c \
		srcs/ft_lstmap.c 

OBJ			= $(SOURCE:%.c=%.o)

OBJB		= $(BONUS:%.c=%.o) $(OBJ)

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@printf "[ libft ] Compiling.  \r"
	@gcc $(FLAGS) -c -g $< -o $@
	@printf "[ libft ] Compiling . \r"
	@printf "[ libft ] Compiling  .\r"

$(NAME): $(OBJ)
	@printf "[ libft ] Compiled \033[0;32mSuccessfully\n\033[0m"
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@printf "[ $(NAME) ] Created \033[0;32mSuccessfully\n\033[0m" $(SUCCESS)

bonus: $(OBJB)
	@ar rc $(NAME) $(OBJB)
	@ranlib $(NAME)
	@printf "[ $(NAME) + bonus] Created \033[0;32mSuccessfully\n\033[0m" $(SUCCESS)

clean:
	@/bin/rm -f $(OBJ) $(OBJB)

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "[ $(NAME) ] \033[0;31mremoved\n\033[0m"

re: fclean all

.PHONY: all bonus clean fclean re
