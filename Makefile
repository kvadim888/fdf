# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 00:10:36 by vkryvono          #+#    #+#              #
#    Updated: 2018/09/12 13:32:38 by vkryvono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := fdf

CC := clang

INC_PATH	:=	./inc
SRC_PATH	:=	./src
OBJ_PATH	:=	./obj
 
INC = -I $(INC_PATH)\
	  -I./libft/includes\
	  -I./libgraph/includes

SRC		:=	main.c\
			reader.c\
			action.c\
			state.c\
			figuration.c\
			camera.c\
			color.c\
			image.c\
			drawing.c

OBJ		:=	$(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

FLAGS	:=	-Wall -Wextra -Werror

OSX_LIB = -framework OpenGL -framework AppKit -lmlx

LIBFT = -L./libft -lft
LIBGRAPH = -L./libgraph -lgraph

all: $(OBJ_PATH) $(NAME)
	
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	$(CC) $(INC) -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
	make -C libft/
	make -C libgraph/
	$(CC) -o $(NAME) $(OBJ) $(OSX_LIB) $(LIBFT) $(LIBGRAPH)

clean:
	rm -rf $(OBJ_PATH)
	make -C libft/ clean
	make -C libgraph/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C libgraph/ fclean

re: fclean all
