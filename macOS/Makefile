# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/22 20:52:58 by fmanetti          #+#    #+#              #
#    Updated: 2022/04/24 23:46:14 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	miniRT

FILES			=	minirt.c								\
					graph/render.c							\
					graph/trace.c							\
					graph/cast_ray.c						\
					graph/window/create_mlx_img.c			\
					graph/window/hook.c						\
					graph/window/bmp_image.c				\
					graph/intersection/intersect.c			\
					graph/intersection/sp_intersect.c		\
					graph/intersection/pl_intersect.c		\
					graph/intersection/sq_intersect.c		\
					graph/intersection/cy_intersect.c		\
					graph/intersection/tr_intersect.c		\
					math/point_ops0.c						\
					math/point_ops1.c						\
					math/clr_ops.c							\
					math/quad_solver.c						\
					math/deg2rad.c							\
					math/normalize.c						\
					math/mtx.c								\
					utilities/fill.c						\
					utilities/my_atoi.c						\
					utilities/my_atof.c						\
					utilities/my_isprint.c					\
					utilities/var0.c						\
					utilities/var1.c						\
					parsing/parse.c							\
					parsing/settings_parser.c				\
					parsing/shapes_parser.c					\
					parsing/object_parser.c					\
					parsing/lst_check/obj_lstadd_back.c		\
					parsing/lst_check/obj_lstnew.c			\
					parsing/lst_check/obj_lstcheck.c		\
					parsing/lst_check/obj_lstlast.c			\
					parsing/lst_check/obj_lstsize.c			\
					errors/errors.c							\
					errors/memory_free.c					\
					errors/lstclear.c
FILES_PATH		=	./srcs/

LIBRARIES		=	include/libft/libft.a					\
					include/minilibx/libmlx.a

HFILES			=	minirt.h								\
					objects.h								\
					struct.h
HFILES_PATH		=	./include/

SOURCE			=	$(addprefix $(FILES_PATH), $(FILES))
HEADERS			=	$(addprefix $(HFILES_PATH), $(HFILES))

OBJ				=	$(SOURCE:%.c=%.o)

CC				= 	clang

FLAGS			=	-L include/minilibx -lmlx -framework OpenGL -framework Appkit
CFLAGS			= 	-Wall -Wextra -Werror -I include/
FSANITIZE		= 	-g3 -O0 -fsanitize=address

RED				=	\033[0;31m
GREEN			=	\033[0;32m
RESET			=	\033[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@($(CC) -o $(NAME) $(SOURCE) $(LIBRARIES) $(FLAGS) $(CFLAGS))
	@printf "$(GREEN)"
	@printf "                   88             88 88888888ba 888888888888  \n"
	@printf "                   ''             '' 88      '8b     88       \n"
	@printf "                                     88      ,8P     88       \n"
	@printf "88,dPYba,,adPYba,  88 8b,dPPYba,  88 88aaaaaa8P'     88       \n"
	@printf "88P'   '88'    '8a 88 88P'   ''8a 88 88''''88'       88       \n"
	@printf "88      88      88 88 88       88 88 88    '8b       88       \n"
	@printf "88      88      88 88 88       88 88 88     '8b      88       \n"
	@printf "88      88      88 88 88       88 88 88      '8b     88       \n"
	@printf "$(RESET)"
	@printf " ___         __                     _   _   _  \n"
	@printf "| _ )_  _   / _|_ __  __ _ _ _  ___| |_| |_(_) \n"
	@printf "| _ \ || | |  _| '  \/ _' | ' \/ -_)  _|  _| | \n"
	@printf "|___/\_, | |_| |_|_|_\__,_|_||_\___|\__|\__|_| \n"
	@printf "     |__/                                      \n"

lib:
	@make re bonus -C include/libft
	@make clean -C include/libft

xlib:
	@make re -C include/minilibx

clean:
	@/bin/rm -f $(OBJ)
	@printf "Object files \033[0;31mremoved\n\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f image.bmp
	@/bin/rm -rf $(NAME).*
	@printf "[ $(NAME) ] \033[0;31mremoved\n\033[0m"

re: fclean all

.PHONY: all clean fclean re

.SILENT: