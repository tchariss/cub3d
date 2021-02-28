// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw_map.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/02/05 16:59:06 by tchariss          #+#    #+#             */
// /*   Updated: 2021/02/21 16:47:22 by tchariss         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3d.h"

void draw_cub(int x, int y, t_all *all, int color)
{
	int x_max = x + PIX_SIZE; // pix_SIZE =32
	int y_max = y + PIX_SIZE; // 100 + 32 -> y_max = 132
	int save_x = x; // изначальной координате х (если 100)
	
	while (y < y_max) // y_max = 132 / y = 100 
	{
		x = save_x; // x = изначальному x
		while (x < x_max) // x = 100
		{
			my_mlx_pixel_put(all, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_again(t_all *all)
{
	int	cor_x = 0;
	int	cor_y = 0;
	// player_2 st;
	// all->plr = &st;
	

	cor_y = 0;
	all->y = 0; // на начало чтения строки 0-ой элемент массива
	while (all->st[all->y] && all->y != all->row) // != NULL 
	{
		all->x = 0; // на начало чтения строки 0-ой элемент массива
		cor_x = 0;
		while (all->st[all->y][all->x] != '\0')
		{
			if (all->st[all->y][all->x] == '1') //[all->x++]
			{	
				draw_cub(cor_x, cor_y, all, 0xD4B8D9); // 0xD4B8D9
			}
			if (all->st[all->y][all->x] == '0' || all->st[all->y][all->x] == 'N' ||
			all->st[all->y][all->x] == 'S' || all->st[all->y][all->x] == 'W' ||
			all->st[all->y][all->x] == 'E')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
			}
			all->x++;
			cor_x = cor_x + PIX_SIZE;
		}
		all->y++; // перешагиваю на след строку массива вниз 
		cor_y = cor_y + PIX_SIZE;
	}
	// ft_cast_ray(all);
	//mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100);
}

void draw_screen(t_all *all) /////////////////////////////////////
{
	
	// all->img = mlx_new_image(all->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	// all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel, &all->line_length, &all->endian);
	// void *mlx = 0;
	// void *win = 0;
	int	cor_x = 0;
	int	cor_y = 0;
	// player_2 st;
	// all->plr = &st;
	

	cor_y = 0;
	all->y = 0; // на начало чтения строки 0-ой элемент массива
	while (all->st[all->y] && all->y != all->row) // != NULL 
	{
		all->x = 0; // на начало чтения строки 0-ой элемент массива
		cor_x = 0;
		while (all->st[all->y][all->x] != '\0')
		{
			if (all->st[all->y][all->x] == '1') //[all->x++]
			{	
				draw_cub(cor_x, cor_y, all, 0xD4B8D9); // 0xD4B8D9
			}
			if (all->st[all->y][all->x] == '0' || all->st[all->y][all->x] == 'N' ||
			all->st[all->y][all->x] == 'S' || all->st[all->y][all->x] == 'W' ||
			all->st[all->y][all->x] == 'E')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
			}
			if (all->st[all->y][all->x] == 'N')
			{
				all->plr.dir = -M_PI_2; // 270 граудсов, но смотрит вверх // M_PI + M_PI_2
				//all->p = all->st[all->y][all->x]; // передаю координаты игроку p, если нахожу N [6][2]
				
				all->plr.x_p = cor_x + PIX_SIZE / 2; // от центра игрока
				all->plr.y_p = cor_y + PIX_SIZE / 2;
			}
			if (all->st[all->y][all->x] == 'S')
			{
				all->plr.dir = M_PI_2; // 90 граудсов, но смотрит вниз
				all->plr.x_p = cor_x + PIX_SIZE / 2;
				all->plr.y_p = cor_y + PIX_SIZE / 2;
			}
			if (all->st[all->y][all->x] == 'W')
			{
				all->plr.dir = M_PI; // влево
				all->plr.x_p = cor_x + PIX_SIZE / 2;
				all->plr.y_p = cor_y + PIX_SIZE / 2;
			}
			if (all->st[all->y][all->x] == 'E')
			{
				all->plr.dir = 0;// вправо
				all->plr.x_p = cor_x + PIX_SIZE / 2;
				all->plr.y_p = cor_y + PIX_SIZE / 2;
			}
			all->x++;
			cor_x = cor_x + PIX_SIZE;
		}
		all->y++; // перешагиваю на след строку массива вниз 
		cor_y = cor_y + PIX_SIZE;
	}
	// printf("draw_screen: \ndir: %f\n", all->plr.dir);
	// printf("x_pl_pos: %f\n", all->plr.x_p);
	// printf("y_pl_pos: %f\n", all->plr.y_p);
	 ////////////////  ////////////////////////////////////////////////////////////////////////////
	//mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100);
	

    // ft_cast_ray(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	// mlx_destroy_image(all->mlx, all->img);
}