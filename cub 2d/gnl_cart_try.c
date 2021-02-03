/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_cart_try.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:57:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/03 18:02:15 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_mms_20200219/mlx.h"
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

typedef struct	all_s
{
	int		x; // позиция по х, у
	int 	y;
	// float	a;    // направление
	// float	fov;  // поле зрение
	char 	**s;
}				t_all;

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1 , s, ft_strlen(s));
	write(1 , "\n", 1);
}

int		gnl_card(t_all *var_gnl)
{
	// char **s;
	// int x;
	// int y;
	// t_all	var_gnl;
	char	*line;
	int		fd;
	// int		ret;

	//ret = 1
	var_gnl->x = 0;
	var_gnl->y = 0;
	var_gnl->s = (char **)malloc(sizeof(char **) * (14 * 25 + 1)); // x * y + 1 ?
	fd = open("cub.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		var_gnl->s[var_gnl->y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
		var_gnl->s[var_gnl->y] = line;
		ft_putstr(var_gnl->s[var_gnl->y]);
		var_gnl->y++;
	}
	var_gnl->s[var_gnl->y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
	var_gnl->s[var_gnl->y] = line;
	ft_putstr(var_gnl->s[var_gnl->y]);
	var_gnl->y++;
	return (0);
}

// int draw_card(t_all var_gnl)
// { 
// 	void *mlx = 0;
//     void *win = 0;
	
// 	gnl_card(var_gnl);
// 	var_gnl.y = 0; // на начало чтения строки 0-ой элемент массива
// 	while (*var_gnl.s[var_gnl.y] != -1)
// 	{
// 		var_gnl.x = 0; // на начало чтения строки 0-ой элемент массива
// 		while (var_gnl.s[var_gnl.y][var_gnl.x] != '\0')
// 		{
// 			if (var_gnl.s[var_gnl.y][var_gnl.x] == '1')
// 				mlx_pixel_put(mlx, win, 100, 100, 0x8B008B);
// 			var_gnl.x++; // шагаю по строке 1 1 0 1
// 		}
// 		var_gnl.y++; // перенагиваю на след строку массива вниз 
// 	}
// }


int main()
{
    void *mlx = 0;
    void *win = 0;
    int cor_x = 0;
    int cor_y = 0;
	int 		i;
	t_all	var_gnl;
	
	i = 0;
	mlx = mlx_init();
    win = mlx_new_window(mlx, 1080, 720, "hello, vikos");
	gnl_card(&var_gnl);
	cor_y = 0;
	var_gnl.y = 0; // на начало чтения строки 0-ой элемент массива
	while (var_gnl.s[var_gnl.y]) // != NULL 
	{
		var_gnl.x = 0; // на начало чтения строки 0-ой элемент массива
		cor_x = 0;
		while (var_gnl.s[var_gnl.y][var_gnl.x] != '\0')  // !!!!!!!!!!!!!!!!!  	выходит из цикла
		{
			if (var_gnl.s[var_gnl.y][var_gnl.x] == '1') //[var_gnl.x++]
			{	
				while (cor_y < cor_y +32)
				{
					cor_x = i * 32;
					while (cor_x < i * 32 + 32)
					{
						mlx_pixel_put(mlx, win, cor_x, cor_y, 0x8B008B);
						i++;
					}
				}
			}	
			var_gnl.x++;
			cor_x++;
			// }
			// else
			// 	var_gnl.x++; // шагаю по строке 1 1 0 1
		}
		var_gnl.y++; // перешагиваю на след строку массива вниз 
		cor_y++;
	}
	mlx_loop(mlx);
//	}
}
