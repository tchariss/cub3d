# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 12:36:09 by tchariss          #+#    #+#              #
#    Updated: 2021/02/22 15:32:43 by tchariss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = cub3d.h

SRC = gnl_card_etc.c draw.c key_process.c raycast.c \

SRCO = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME) : $(SRCO) ./libft/libft.a ./mlx/libmlx.dylib
	gcc ./mlx -framework OpenGL -framework AppKit main.c
	./a.out

$(NAME) : $(SRCO)
	make -C ./libft
	make -C ./mlx
	gcc $(FLAGS) -L./libft/libft.a -L./mlx/mlx.h \
		-framework OpenGL -framework AppKit main.c && ./a.out
# ./libft/libft.a :
# 	make -C ./libft/

# ./mlx/libmlx.dylib :
# 	make -C ./minilibx_mms_20200219/
# 	cp ./mlx/libmlx.dylib ./

%.o: %.c $(HEADER)
	gcc $(FLAGS) -I ./mlx.h -c $< -o $@

clean:
	rm -f $(SRCO)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	rm -f ./mlx/libmlx.dylib
	make fclean -C ./libft/

re: fclean all

.PHONY:  all clean fclean re
