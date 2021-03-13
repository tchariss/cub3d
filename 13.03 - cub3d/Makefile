# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 12:36:09 by tchariss          #+#    #+#              #
#    Updated: 2021/03/07 15:08:53 by tchariss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAP = ./try.cub

SRC = gnl_card_etc.c draw.c key_process.c raycast.c \
		./get_next_line/get_next_line.c  ./get_next_line/get_next_line_utils.c \

SRCO = $(SRC:.c=.o)

FLAGS = -g -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

$(NAME) : $(SRCO) 
	rm -rf $(NAME)
	make -C ./libft
	gcc $(FLAGS) $(SRCO) libmlx.dylib -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)

run : all	
	./$(NAME) $(MAP)

clean:
	rm -f $(SRCO)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
