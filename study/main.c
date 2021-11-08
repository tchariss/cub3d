/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:19:08 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/19 16:19:18 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_all	all;
	
	all = *(t_all *)ft_calloc(sizeof(t_all), 1);
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "hello, vikos");
	all.img = mlx_new_image(all.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all.addr = mlx_get_data_addr(all.img, &all.bits_per_pixel, &all.line_length, &all.endian);
	gnl_card(&all);
	draw_screen(&all);
	ft_cast_ray(&all);

	
	all.w = 0;
	mlx_hook(all.win, 2, 0, &press_key, &all);
	// mlx_hook(all.win, 3, 1L<<1, &releas, &all);
	mlx_hook(all.win, 17, 0L, &my_close, all.img);
	// mlx_loop_hook(all.mlx, &key_process, &all);
	
	    //    int (void *mlx_ptr, int (*funct_ptr)(), void *param); !!!!! Зациклить действия и не чистить окно
	mlx_loop(all.mlx);
}
