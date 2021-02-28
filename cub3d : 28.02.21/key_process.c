/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:03:13 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/28 13:08:26 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void     close_my(void *mlx, void *win)
{
    mlx_destroy_window(mlx, win);
}

int my_close(t_all *all)
{
	free(all);
    exit(0);
}

int press(int keycode, t_all *all)
{
	printf("%d\n", keycode);
	printf("%f\n", all->plr.x_p);
	printf("%f\n", all->plr.y_p);
	if (keycode == 53)
		exit(0);
	if (keycode == 13 && all->w == 0)
	{
		all->w = 1;
	}
	if (keycode == 1 && all->s == 0) // S
	{
		all->s = 1;	
	}
	if (keycode == 0 && all->a == 0) // A
	{
		all->a = 1;
	}
	if (keycode == 2 && all->d == 0) // D
	{
		all->d = 1;
	}
	if (keycode == 123 && all->turn_left == 0)
	{
		all->turn_left = 1;
	}
	if (keycode == 124 && all->turn_right == 0) 
	{
		all->turn_right = 1;
	}
	return (0);
    // mlx_clear_window(all->mlx, all->win);
	// ft_to_3d(all);
	ft_cast_ray(all);
	// ft_to_3d(&all);
}

int pushback(int keycode, t_all *all)
{	
	if (keycode == 13 && all->w == 1)
	{
		all->w = 0;
	}
	if (keycode == 1 && all->s == 1) // S
	{
		all->s = 0;	
	}
	if (keycode == 0 && all->a == 1) // A
	{
		all->a = 0;
	}
	if (keycode == 2 && all->d == 1) // D
	{
		all->d = 0;
	}
	if (keycode == 123 && all->turn_left == 1)
	{
		all->turn_left = 0;
	}
	if (keycode == 124 && all->turn_right == 1) 
	{
		all->turn_right = 0;
	}
	return (0);
    //mlx_clear_window(all->mlx, all->win);
	draw_again(all);
	// ft_to_3d(all);
}

// int stop_walk(t_all *all)
// {
// 	float t_x = all->plr.x_p;
// 	float t_y = all->plr.y_p;
	
// 	if (all->st[((int)all->plr.y_p)/ PIX_SIZE][((int)all->plr.x_p)/ PIX_SIZE] == '1' 
// 	|| all->st[(int)(all->plr.y_p + 0.5 * sin(all->plr.start + M_PI_2))/ PIX_SIZE][(int)(all->plr.x_p + 0.5 * cos(all->plr.start + M_PI_2)) / PIX_SIZE] == '1'
// 	|| all->st[(int)(all->plr.y_p + 0.5 * sin(all->plr.start - M_PI_2))/ PIX_SIZE][(int)(all->plr.x_p + 0.5 * cos(all->plr.start - M_PI_2)) / PIX_SIZE] == '1'
// 	|| all->st[(int)(all->plr.y_p + 0.5 * sin(all->plr.start + M_PI))/ PIX_SIZE][(int)(all->plr.x_p + 0.5 * cos(all->plr.start + M_PI)) / PIX_SIZE] == '1') // условие для входа в стену
// 	{
// 		all->plr.x_p = t_x;
// 		all->plr.y_p = t_y;
// 	}
// 	return (0);
// }

int	press_key(t_all *all) // esc
{

	float t_x = all->plr.x_p;
	float t_y = all->plr.y_p;
	// int i = 0;
	
	if (all->w == 1) // W
	{
		// while (i < 3) // для ускорения игрока
		// {
			all->plr.y_p += sin(all->plr.dir);
			all->plr.x_p += cos(all->plr.dir);	
		// 	stop_walk(all);
		// 	i++;
		// }		
	}
	if (all->s == 1) // S
	{
		// while (i < 3)
		// {
			all->plr.y_p -= sin(all->plr.dir);
			all->plr.x_p -= cos(all->plr.dir);
		// 	stop_walk(all);
		// 	i++;
		// }	
	}
	if (all->a == 1) // A
	{
		// while (i < 3)
		// {
			all->plr.y_p -= cos(all->plr.dir);
			all->plr.x_p += sin(all->plr.dir);
			// stop_walk(all);
		// 	i++;
		// }	
	}
	if (all->d == 1) // D
	{
		// while (i < 3)
		// {
			all->plr.y_p += cos(all->plr.dir);
			all->plr.x_p -= sin(all->plr.dir);
		// 	stop_walk(all);
		// 	i++;
		// }	
	}
	if (all->turn_left == 1)
	{
		all->plr.dir -= 0.1;
        if (all->plr.dir < 0)
            all->plr.dir += M_PI * 2;
	}
	if (all->turn_right == 1) 
	{
		all->plr.dir += 0.1;
		if (all->plr.dir > M_PI * 2)
            all->plr.dir -= M_PI * 2;
	}
	if (all->st[((int)all->plr.y_p)/ PIX_SIZE][((int)all->plr.x_p)/ PIX_SIZE] == '1' 
	|| all->st[(int)(all->plr.y_p + 0.5 * sin(all->plr.start + M_PI_2))/ PIX_SIZE][(int)(all->plr.x_p + 0.5 * cos(all->plr.start + M_PI_2)) / PIX_SIZE] == '1'
	|| all->st[(int)(all->plr.y_p + 0.5 * sin(all->plr.start - M_PI_2))/ PIX_SIZE][(int)(all->plr.x_p + 0.5 * cos(all->plr.start - M_PI_2)) / PIX_SIZE] == '1'
	|| all->st[(int)(all->plr.y_p + 0.5 * sin(all->plr.start + M_PI))/ PIX_SIZE][(int)(all->plr.x_p + 0.5 * cos(all->plr.start + M_PI)) / PIX_SIZE] == '1') // условие для входа в стену
	{
		all->plr.x_p = t_x;
		all->plr.y_p = t_y;
	}
	return (0);
}


int	key_process(t_all *all)
{
	press_key(all);	
	draw_again(all);
	// ft_to_3d(all);
	ft_cast_ray(all);
	
	
	mlx_hook(all->win, 2, 1L<<0, press, all); // &press
	mlx_hook(all->win, 3, 1L<<1, pushback, all);
	mlx_hook(all->win, 17, 0, my_close, all->img);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0); // помещает img в окно или рисует изображение внутри
	mlx_do_sync(all->mlx);
	return 0;
}
