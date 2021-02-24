/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:03:13 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/22 17:37:24 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void     close_my(int keycode, void *mlx, void *win)
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
	printf("%c\n", **all->st);
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
    //mlx_clear_window(all->mlx, all->win);
	// draw_again(all);
	draw_again(all);
	ft_cast_ray(all);
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
	// draw_again(all);
}


	

int	press_key(t_all *all) // esc
{
	// printf("%d\n", keycode);
	
	// printf("press_key: \ndir: %f\n", all->plr.dir);
	// printf("x_pl_place: %f\n", all->plr.x_p); 
	// printf("y_pl_place: %f\n", all->plr.y_p);
	// mlx_clear_window (all->mlx, all->win);
	//draw_screen(all);
	// ft_cast_ray(all);
	
	if (all->w == 1) // W
	{
		// all->plr.y_p--;
		// printf("x_place before keycode: %f\n", all->place_x);
		all->plr.y_p += sin(all->plr.dir) * 4;
		all->plr.x_p += cos(all->plr.dir) * 4;
	}
	if (all->s == 1) // S
	{
		//mlx_clear_window (all->mlx, all->win);
		//draw_screen(all);
		// all->plr.y_p++;
		all->plr.y_p -= sin(all->plr.dir) * 4;
		all->plr.x_p -= cos(all->plr.dir) * 4;
	}
	if (all->a == 1) // A
	// 	//all->plr.dir -= 0.1;
	{
		all->plr.x_p += sin(all->plr.dir) * 4;
		all->plr.y_p -= cos(all->plr.dir) * 4;
		// all->a = 1;
	}
	if (all->d == 1) // D
	// 	// all->plr.dir += 0.1;
	{
		all->plr.x_p -= sin(all->plr.dir) * 4;
		all->plr.y_p += cos(all->plr.dir) * 4;
		// all->d = 1;
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
	return (0);
}


int	key_process(t_all *all)
{
// 	// draw_again(all);
// 	//movement(all);
// 	// ft_cast_ray(all);
	
	press_key(all);
	draw_again(all);
	ft_cast_ray(all);
	// printf("%f\n", all->plr.x_p);
	// printf("%f\n", all->plr.y_p);
	mlx_hook(all->win, 2, 1L<<0, press, all); // &press
	mlx_hook(all->win, 3, 1L<<1, pushback, all);
	mlx_hook(all->win, 17, 0, my_close, all->img);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100); // помещает img в окно или рисует изображение внутри
	mlx_do_sync(all->mlx);
	return 0;
}
// int	key_process(t_all *all)
// {
// 	// draw_again(all);
// 	//movement(all);
// 	// ft_cast_ray(all);
// 	mlx_hook(all->win, 2, 0, &press_key, &all); // &press
// 	mlx_hook(all->win, 3, 1L<<1, &pushback, &all);
// 	mlx_hook(all->win, 17, 0L, &my_close, all->img);
// 	mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100);
// 	return 0;
// }