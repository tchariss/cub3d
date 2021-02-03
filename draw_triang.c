/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:23:17 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/03 16:24:54 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_mms_20200219/mlx.h"


int main()
{
    void *mlx = 0;
    void *win = 0;
    int x = 100;
    int y = 100;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1080, 720, "hello, vikos");
    
	while (y < 600)
    {
		x = 0;
		while (x < 300)
        {
			mlx_pixel_put(mlx, win, x, y, 0xEDDBFF);
            x++;
        }
        y++;
    }
    mlx_loop(mlx);
}
