# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/22 20:52:58 by fmanetti          #+#    #+#              #
#    Updated: 2020/09/01 18:04:41 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		miniRT

SOURCE = 	main.c \
			srcs/graph/render.c \
			srcs/graph/trace.c \
			srcs/graph/cast_ray.c \
			srcs/graph/window/draw.c \
			srcs/graph/window/hook.c \
			srcs/graph/intersection/intersect.c \
			srcs/graph/intersection/sp_intersect.c \
			srcs/graph/intersection/pl_intersect.c \
			srcs/graph/intersection/sq_intersect.c \
			srcs/graph/intersection/cy_intersect.c \
			srcs/graph/intersection/tr_intersect.c \
			srcs/math/matrix_ops.c \
			srcs/math/point_ops.c \
			srcs/math/distance.c \
			srcs/math/quad_solver.c \
			srcs/math/deg2rad.c \
			srcs/math/normalize.c \
			srcs/utilities/start.c \
			srcs/utilities/fill.c \
			srcs/utilities/my_atoi.c \
			srcs/utilities/my_atof.c \
			srcs/utilities/var0.c \
			srcs/parsing/start_parse.c \
			srcs/parsing/settings_parser.c \
			srcs/parsing/shapes_parser.c \
			srcs/parsing/object_parser.c \
			srcs/parsing/lst_check/obj_lstadd_back.c \
			srcs/parsing/lst_check/obj_lstnew.c \
			srcs/parsing/lst_check/obj_lstcheck.c \
			srcs/parsing/lst_check/obj_lstlast.c \
			srcs/parsing/lst_check/obj_lstsize.c \
			srcs/errors/errors_1.c

INCLUDE =	libft.a \
			libmlx.a

OBJ			= $(SOURCE:%.c=%.o)

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@printf "[ miniRT ] Compiling.  \r"
	@printf "[ miniRT ] Compiling . \r"
	@printf "[ miniRT ] Compiling  .\r"

$(NAME): $(OBJ)
	@make -C include/libft/
	@make bonus -C include/libft/
	@make -C include/minilibx
	@cp include/libft/libft.a .
	@cp include/minilibx/libmlx.a .
	@printf "[ libmlx.a ] Created \033[0;32mSuccessfully\n\033[0m" $(SUCCESS)
	@gcc -g -lmlx -L include/minilibx -framework OpenGL -framework AppKit -lz $(SOURCE) $(INCLUDE) -g3 -fsanitize=address
	@printf "[ miniRT ] Compiled \033[0;32mSuccessfully\n\033[0m"

bonus: $(NAME)
	@printf "[ $(NAME) + bonus] Created \033[0;32mSuccessfully\n\033[0m" $(SUCCESS)

clean:
	@make clean -C include/libft/
	@make clean -C include/minilibx/
	@/bin/rm -f $(OBJ)
	@printf "Object files \033[0;31mremoved\n\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
	@make fclean -C include/libft/
	@/bin/rm -f libmlx.a
	@printf "[ libmlx.a ] \033[0;31mremoved\n\033[0m"
	@/bin/rm -fr a.out*
	@printf "[ $(NAME) ] \033[0;31mremoved\n\033[0m"

re: fclean all

.PHONY: all clean fclean re