/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pix32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:10:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/11 12:59:14 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// функция, которая рисует квадраты подаваемого размера от посылаемых координат

#include "minilibx_mms_20200219/mlx.h"

#define CUBE_SIZE 32

// void draw(int x, int y, void *mlx, void *win)
// {
// 	int x_max = x + CUBE_SIZE;
// 	int y_max = y + CUBE_SIZE;
// 	int save_y = y;
	
// 	while (x < x_max)
// 	{
// 		y = save_y;
// 		while (y < y_max)
//         {
// 			mlx_pixel_put(mlx, win, x, y, 0xEDDBFF);
//             y++;
//         }
// 		x++;
// 	}
// }

void draw(int x, int y, void *mlx, void *win)
{
	int x_max = x + CUBE_SIZE; // PIX_SIZE =32
	int y_max = y + CUBE_SIZE; // 100 + 32 -> y_max = 132
	int save_x = x; //изначальной координате х (если 100)
	
	while (y < y_max) // y_max = 132 / y = 100 
	{
		x = save_x; // x = изначальному x
		while (x < x_max) // x = 100
		{
			mlx_pixel_put(mlx, win, x, y, 0x8B008B);
            x++;
		}
		y++;
	}
}

int main()
{
    void *mlx = 0;
    void *win = 0;

	mlx = mlx_init();
    win = mlx_new_window(mlx, 720, 540, "hello, vikos");
    
	draw(0, 0, mlx, win);
	draw(64, 64, mlx, win);
	draw(128, 128, mlx, win);

    mlx_loop(mlx);
}