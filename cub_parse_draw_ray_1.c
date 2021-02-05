/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_card.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:57:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/05 15:42:32 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_mms_20200219/mlx.h"
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include <math.h>
#define PIX_SIZE 32
#define PI 3.14

typedef struct	player_1
{
	float		x_p;
	float		y_p;
	float		dir;
	float		start;
	float		end;
	//int		p; // сам игрок
	//float x, y; // позиция по х, у
	//float a;    // направление
	//float fov;  // поле зрение
}				player_2;

typedef struct	all_s
{
	int		x; // позиция по х, у
	int 	y;
	int		p;
	int		row; // столбцы
	// float	a;    // направление
	// float	fov;  // поле зрение
	char 	**s;
	player_2 *plr;
}				t_all;

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1 , s, ft_strlen(s));
	write(1 , "\n", 1);
}

int size_map(void)
{
	char	*line;
	int		fd;
	int		i;
	
	i = 0;
	fd = open("cub.cub", O_RDONLY);
	while(get_next_line(fd, &line) > 0)
	{
		i = i + ft_strlen(line);
	}
	i++;
	return (i);
}

int		gnl_card(t_all *map)
{
	char	*line;
	int		fd;

	map->row = 0;
	map->x = 0;
	map->y = 0;
	map->s = (char **)malloc(sizeof(char **) * (size_map())); // x * y + 1 ?
	fd = open("cub.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		map->s[map->y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
		map->s[map->y] = line;
		ft_putstr(map->s[map->y]);
		map->y++;
		map->row++;
	}
	map->s[map->y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
	map->s[map->y] = line;
	ft_putstr(map->s[map->y]);
	map->y++;
	map->row++;
	return (0);
	
}

void	ft_cast_ray(t_all *all, player_2 *str, void *mlx, void *win)
{
	while (all->s[(int)str->y_p / PIX_SIZE][(int)str->x_p / PIX_SIZE] != '1')
	{
		str->x_p += cos(str->dir);
		str->y_p += sin(str->dir);
		
		mlx_pixel_put(mlx, win, str->x_p, str->y_p, 0x22223B);
		//str->dir = str->dir + 0.5; // кривой луч
	}
	//str->dir = str->dir + 0.5;
}

// int move(int key, t_all *all)
// {
	
// }

void draw_cub(int x, int y, void *mlx, void *win, int color)
{
	int x_max = x + PIX_SIZE; // pix_SIZE =32
	int y_max = y + PIX_SIZE; // 100 + 32 -> y_max = 132
	int save_x = x; // изначальной координате х (если 100)
	
	while (y < y_max) // y_max = 132 / y = 100 
	{
		x = save_x; // x = изначальному x
		while (x < x_max) // x = 100
		{
			mlx_pixel_put(mlx, win, x, y, color);
            x++;
		}
		y++;
	}
}


int main()
{
	void *mlx = 0;
	void *win = 0;
	int	cor_x = 0;
	int	cor_y = 0;
	t_all	map;
	player_2 st;

	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1020, 720, "hello, vikos");
	gnl_card(&map);
	cor_y = 0;
	map.y = 0; // на начало чтения строки 0-ой элемент массива
	while (map.s[map.y] && map.y != map.row) // != NULL 
	{
		map.x = 0; // на начало чтения строки 0-ой элемент массива
		cor_x = 0;
		while (map.s[map.y][map.x] != '\0')
		{
			if (map.s[map.y][map.x] == '1') //[map.x++]
			{	
				draw_cub(cor_x, cor_y, mlx, win, 0xD4B8D9);
			}
			if (map.s[map.y][map.x] == '0')
			{
				draw_cub(cor_x, cor_y, mlx, win, 0xE5E5E5);
			}
			if (map.s[map.y][map.x] == 'N')
			{

				st.dir = -M_PI_2; // 270 граудсов, но смотрит вверх // M_PI + M_PI_2
				//map.p = map.s[map.y][map.x]; // передаю координаты игроку p, если нахожу N [6][2]
				st.x_p = cor_x + PIX_SIZE / 2; // от центра игрока
				st.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, mlx, win, 0x8E9AAF);
			}
			if (map.s[map.y][map.x] == 'S')
			{
				
				st.dir = M_PI_2; // 90 граудсов, но смотрит вниз
				st.x_p = cor_x + PIX_SIZE / 2;
				st.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, mlx, win, 0x8E9AAF);
			}
			if (map.s[map.y][map.x] == 'W')
			{
				
				st.dir = M_PI; // влево
				st.x_p = cor_x + PIX_SIZE / 2;
				st.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, mlx, win, 0x8E9AAF);
			}
			if (map.s[map.y][map.x] == 'E')
			{
				st.dir = 0;// вправо
				st.x_p = cor_x + PIX_SIZE / 2;
				st.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, mlx, win, 0x8E9AAF);
			}
			map.x++;
			cor_x = cor_x + PIX_SIZE;
		}
		map.y++; // перешагиваю на след строку массива вниз 
		cor_y = cor_y + PIX_SIZE;
	}
	ft_cast_ray(&map, &st, mlx, win);
	mlx_loop(mlx);
}
