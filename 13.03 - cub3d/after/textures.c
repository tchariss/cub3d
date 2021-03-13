/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:07:56 by tchariss          #+#    #+#             */
/*   Updated: 2021/03/05 16:11:12 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
​
//  double		min_length(double horz, double vert, t_all *all)
// {
// 	if (horz > vert)
// 	{
// 		all->calc.x_or_y = all->vert_y;
// 		if (all->player.ang_start < M_PI + M_PI_2 &&
// 				all->player.ang_start > M_PI_2)
// 			all->flag.west = 1;
// 		else
// 			all->flag.east = 1;
// 		return (vert);
// 	}
// 	else
// 	{
// 		all->calc.x_or_y = all->horz_x;
// 		if (all->player.ang_start < 2 * M_PI && all->player.ang_start > M_PI)
// 			all->flag.north = 1;
// 		else
// 			all->flag.south = 1;
// 		return (horz);
// 	}
// }
// в структуру 	t_textures			tex;
	// t_textures			txt2;
	// t_textures			txt3;
	// ..
	// t_sprite			 *sprite;
​
​
// int col_tex(t_all *all, double coef, int top_wall, int save_top_wall)
// {
// 	int		color;
// ​
// 	color = all->tex1.addr[(int)((top_wall - save_top_wall) * coef) * all->tex1.width + ((int)(all->calc.x_or_y * 2) % all->tex1.width)];
// 	return (color);
// }

​
static void		get_addr_textures(t_all *all)
{
	all->tex.addr = (int*)mlx_get_all_addr(all->tex.txt, &all->tex.bits_per_pixel, &all->tex.line_length, &all->tex.endian);
}
​
void			get_textures(t_all *all)
{
	all->tex.txt = mlx_xpm_file_to_image(all->mlx, all->path.north, &all->tex.width, &all->tex.height);
}
​
void	draw_floor(t_all *all, int top_wall)
{
	int		floor;
​
	floor = top_wall;
	while (floor < all->height - 1)
		my_mlx_pixel_put(all, all->pixel, floor++, all->color_floor);
}
​
int		color_in_textures(t_all *all, double coef, int top_wall, int save)
{
	int		color;
​
	if (all->flag.north == 1)
		color = all->tex.addr[(int)((top_wall - save) * coef) *
				all->tex.width + ((int)(all->plr.y_p * 2) %
				all->tex.width)]; /////// all->calc.x_or_y
	return (color);
}
​
void	draw_sky(t_all *all, int top_wall)
{
	int		sky;
​
	sky = 0;
	while (sky < top_wall)
		my_mlx_pixel_put(all, all->pixel, sky++, all->color_sky);
}
​
void	draw_wall(t_all *all)
{
	int		all->height_wall;
	int		top_wall;
	int		bottom_wall;
	int		save;
	double	coef;
​
	all->height_wall = (PIX_SIZE / all->distance_real) * all->p_dis;
	// all->height_wall = (int)((all->calc.dis_to_proj / (all->calc.min_len * 64)) * all->height);
	top_wall = (SCREEN_HEIGHT / 2) - (all->height_wall / 2);
	bottom_wall = (SCREEN_HEIGHT / 2) + (all->height_wall / 2);
	coef = 64.0 / all->height_wall;
	save = top_wall;
	if (bottom_wall > all->height)
		bottom_wall = all->height - 1;
	if (top_wall < 0)
		top_wall = 0;
	obj = mlx_put_image_to_window
	while (top_wall < bottom_wall)
	{
		my_mlx_pixel_put(all, all->pixel, top_wall,
							color_in_textures(all, coef, top_wall, save));
		top_wall++;
	}
	draw_floor(all, top_wall);
}