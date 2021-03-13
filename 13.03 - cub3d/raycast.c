/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:17:59 by tchariss          #+#    #+#             */
/*   Updated: 2021/03/12 19:46:44 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void go_play(t_all *all, int x, int y)
// {
// 	y = all->plr.y_p - 16 / 2;
// 	while (y < all->plr.y_p + 16 / 2)
// 	{
// 		x = all->plr.x_p - 16 / 2;
// 		while (x < all->plr.x_p + 16 / 2)
// 		{
// 			my_mlx_pixel_put(all, x, y, 0xffffd1);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	ft_cast_ray(t_all *all)
{
	all->plr.start = all->plr.dir - M_PI_6; // начало веера луча | /
	all->plr.end = all->plr.dir + M_PI_6; // конец веера луча \ |
	int count = 0;
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
			// my_mlx_pixel_put(all, all->save_x_p, all->save_y_p, 0x00FF00); //   НЕ НУЖНО
			// ft_to_3d(all);
			// count++;
			all->save_x_p += cos(all->plr.start);
			all->save_y_p += sin(all->plr.start);
			//printf("%f\n", all->save_x_p);
			// ft_to_3d(all);
			all->p_dis = (SCREEN_WIDTH / 2) / (tan(M_PI_6)); // длина до стены в проекции 2д
    		all->distance_real = sqrt(pow((all->save_x_p - all->plr.x_p),(2)) + pow((all->save_y_p - all->plr.y_p),(2))) * cos(all->plr.start - all->plr.dir); // длина до стены реальная
			all->height_wall = (PIX_SIZE / all->distance_real) * all->p_dis; // высота стены реальная 	
			// all->count++
		}
		all->x_col_tex = (int)all->save_x_p;
		all->y_col_tex = (int)all->save_y_p;

		// printf("x -> %i || y-> %i || count -> %d\n", (int)all->save_x_p,  (int)all->save_y_p, count);
		// printf("---all->save_x_p--------%f, vount - %i\n", all->save_x_p / 64.0, count);  	
		// printf("---all->save_y_p--------%i,   vount - %i\n", (int)all->save_y_p % 64, count);                                

		count++;
		ft_to_3d(all);
		          
		all->plr.start = all->plr.start + M_PI_3 / SCREEN_WIDTH;
	}
	// printf("\nСolor - %i\n", color_tex(all));
	all->count = 0;
	// all->i = 0;
}



