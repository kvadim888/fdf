# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkryvono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 00:45:42 by vkryvono          #+#    #+#              #
#    Updated: 2018/09/07 16:13:11 by vkryvono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		:=	libgraph.a

INC_PATH	:=	./includes
SRC_PATH	:=	./sources
OBJ_PATH	:=	./objects

RAW_SRC		=	$(shell find $(SRC_PATH) -type f | grep -E "\.c$$")
OBJ			=	$(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

CC			:=	clang
FLAGS		:=	-Wall -Wextra -Werror
SRC			=	$(RAW_SRC:./sources/%=%)
INC			=	-I./libft/includes\
				-I $(INC_PATH)

LIBFT = -L ./libft -lft

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	$(CC) $(INC) -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)	
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
