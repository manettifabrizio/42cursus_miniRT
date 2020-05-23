# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/22 20:52:58 by fmanetti          #+#    #+#              #
#    Updated: 2020/05/23 11:05:29 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		miniRT

SOURCE = 	main.cpp \
			srcs/graph/intersect.cpp \
			srcs/graph/render.cpp \
			srcs/graph/start.cpp \
			srcs/math/matrix_ops.cpp \
			srcs/math/point_ops.cpp \
			srcs/math/quad_solver.cpp \
			srcs/utilities/deg2rad.cpp \
			srcs/utilities/fill.cpp \
			srcs/utilities/normalize.cpp

OBJ			= $(SOURCE:%.c=%.o)

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@printf "[ miniRT ] Compiling.  \r"
	#@gcc $(FLAGS) -c -g $< -o $@
	@c++ -o simpleshapes $(SOURCE) -O3 -std=c++11
	@printf "[ miniRT ] Compiling . \r"
	@printf "[ miniRT ] Compiling  .\r"

$(NAME): $(OBJ)
	c++ -o simpleshapes $(SOURCE) -O3 -std=c++11
	@printf "[ miniRT ] Compiled \033[0;32mSuccessfully\n\033[0m"
	#@make -C include/libft/
	#@cp include/libft/libft.a ./$(NAME)
	#@ar rc $(NAME) $^
	#@ranlib $(NAME)
	#@printf "[ $(NAME) ] Created \033[0;32mSuccessfully\n\033[0m" $(SUCCESS)

bonus: $(NAME)
	@printf "[ $(NAME) + bonus] Created \033[0;32mSuccessfully\n\033[0m" $(SUCCESS)

clean:
	#@make clean -C include/libft/
	@/bin/rm -f $(OBJ)
	@/bin/rm -f a.out
	@printf "Object files \033[0;31mremoved\n\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	#@make fclean -C include/libft/
	@printf "[ $(NAME) ] \033[0;31mremoved\n\033[0m"

re: fclean all

.PHONY: all clean fclean re