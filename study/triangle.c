// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   triangle.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/01/30 17:21:21 by tchariss          #+#    #+#             */
// /*   Updated: 2021/02/01 16:12:38 by tchariss         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minilibx_mms_20200219/mlx.h"


// void		close(int keycode, void *mlx, void *win)
// {
// 	mlx_destroy_window(mlx, win);
// }
typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

void            close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
}

int main()
{
	t_vars    vars;
    int x = 100;
    int y = 100;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1080, 720, "hello, vikos");
    
	while (y++ < 600)
    {
		x = y;
		while (x++ < 300)
			mlx_pixel_put(vars.mlx, vars.win, x, y, 0xEDDBFF);
	}
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    mlx_loop(vars.mlx);
    // mlx_destroy_window(mlx, win);
   // mlx_loop(vars.mlx);
	// mlx_destroy_window(vars->mlx, vars->win);
}



/*
Сердце нашего 3D-движка – вот этот цикл:

float c = 0;   
for (; c<20; c+=.05) {
    float x = player_x + c*cos(player_a);
    float y = player_y + c*sin(player_a);
    if (map[int(x)+int(y)*map_w]!=' ') break;
}
*/