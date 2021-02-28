/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:17:59 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/28 14:22:10 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void view_wall(t_all *all)
// {
// 	if 
// 	all->plr.x_p = all->save_x_p;                                            
// 	all->plr.y_p = all->save_y_p;
// }

void go_play(t_all *all, int x, int y)
{
	y = all->plr.y_p - 16 / 2;
	while (y < all->plr.y_p + 16 / 2)
	{
		x = all->plr.x_p - 16 / 2;
		while (x < all->plr.x_p + 16 / 2)
		{
			my_mlx_pixel_put(all, x, y, 0xffffd1);
			x++;
		}
		y++;
	}
}

void	ft_cast_ray(t_all *all)
{
	printf("\n - Сount - %i", all->count);
	// float dis_real_1;
	// float dis_real_2;
	// all->img = mlx_new_image(all->mlx, 808, 648);
	// all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel, &all->line_length, &all->endian);
	//mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100);	
	all->plr.start = all->plr.dir - M_PI_6; // начало веера луча | /
	all->plr.end = all->plr.dir + M_PI_6; // конец веера луча \ |
	while (all->plr.start <= all->plr.end)
	{
		all->save_x_p = all->plr.x_p;
		all->save_y_p = all->plr.y_p;
		// rem_x_p = all->plr.x_p;
		// rem_y_p = all->plr.y_p;
		
		while (all->st[((int)all->save_y_p)/ PIX_SIZE][((int)all->save_x_p) / PIX_SIZE] != '1' &&
		all->st[((int)all->save_y_p)/ PIX_SIZE][((int)all->save_x_p) / PIX_SIZE] != ' ') // пока не равно стене, печатаю попиксельно луч
		{
			if (all->st[(int)(all->save_y_p + 0.5 * sin(all->plr.start + M_PI_2))/ PIX_SIZE][(int)(all->save_x_p + 0.5 * cos(all->plr.start + M_PI_2)) / PIX_SIZE] == '1'
			|| all->st[(int)(all->save_y_p + 0.5 * sin(all->plr.start - M_PI_2))/ PIX_SIZE][(int)(all->save_x_p + 0.5 * cos(all->plr.start - M_PI_2)) / PIX_SIZE] == '1')
				break;
			my_mlx_pixel_put(all, all->save_x_p, all->save_y_p, 0x00FF00); //   НЕ НУЖНО
			// ft_to_3d(all);
			// count++;
			all->save_x_p += cos(all->plr.start);
			all->save_y_p += sin(all->plr.start);
			// ft_to_3d(all);
			all->p_dis = (SCREEN_WIDTH / 2) / (tan(M_PI_6)); // длина до стены в проекции 2д
    		all->distance_real = sqrt(pow((all->save_x_p - all->plr.x_p),(2)) + pow((all->save_y_p - all->plr.y_p),(2))); // длина до стены реальная
			all->height_wall = (PIX_SIZE / all->distance_real) *  all->p_dis; // высота стены реальная 	
			// all->count++;
		}
		ft_to_3d(all);
		// count++;
		// if (all->st[((int)all->save_y_p)/ PIX_SIZE][((int)all->save_x_p) / PIX_SIZE] == '1')
		// 	dis_real_1 = sqrt(pow((all->save_x_p - all->plr.x_p),(2)) + pow((all->save_y_p - all->plr.y_p),(2)));
		all->plr.start = all->plr.start + M_PI_3 / SCREEN_WIDTH;
		// ft_to_3d(all);
	}	
	printf("\n AFTER - Сount - %i\n", all->count);
	all->count = 0;
}



