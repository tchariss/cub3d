CC = gcc
CFLAGS = -Wall -Wextra -Werror
 
NAME = cub3d
 
SRCS_DIR = ./srcs
SRCS_NAME = #... files.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
 
LIB_NAME = ft
LIB_DIR = ./lib
LIB = $(addprefix $(LIB_DIR)/, libft.a)
 
MLX_NAME = mlx
MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)
 
 
$(NAME) : $(OBJS)
    $(MAKE) -C $(LIB_DIR) bonus
    $(MAKE) -C $(MLX_DIR) all
    $(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) -L$(MLX_DIR) -l$(MLX_NAME) \
           -framework OpenGL -framework AppKit $^ -o $@
 
$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
    $(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIB_DIR) -c $< -o $@
 
 
all : $(NAME)
 
clean :
    $(MAKE) -C $(LIB_DIR) clean
    $(MAKE) -C $(MLX_DIR) clean
    rm -rf $(OBJS)
 
fclean :
    $(MAKE) -C $(LIB_DIR) fclean
    $(MAKE) -C $(MLX_DIR) fclean
    rm -rf $(NAME) $(OBJS)
 
re : fclean all
 
bonus : all
 
.PHONY : all clean fclean re bonus

 

