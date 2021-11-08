/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load_and_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:15:20 by tchariss          #+#    #+#             */
/*   Updated: 2021/03/05 17:12:24 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;


	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

int main()
{
		void	*mlx;
		void	*win;
		t_img	img;
		int		count_h;
		int		count_w;


		mlx = mlx_init();
		win = mlx_new_window(mlx, 500, 500, "my_mlx");
		img.ptr = mlx_xpm_file_to_image(mlx, "./textures/north.xpm", &img.width, &img.height);
		img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);

		count_h = -1;
		while (++count_h < img.height)
		{
			count_w = -1;
			while (++count_w < img.width / 2)
			{
				if (count_w % 2)
					img.data[count_h * img.width + count_w] = 0xFFFFFF;
				else
					img.data[count_h * img.width + count_w] = 0xFF0000;
			}
		}
		mlx_put_image_to_window(mlx, win, img.ptr, 50, 50);
		mlx_loop(mlx);
		return (0);
}

//____________________________________________________________

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 800, 600, "title");
    img.img = mlx_new_image(mlx.mlx, 400, 300);
    img.data = (int *)mlx_get_data_addr(img.img, &(img.bpp), &(img.line_size), &(img.endian));
 
    int y = 0;
    while (y < 300)
    {
        int x = 0;
        while (x < 400)
        {
            if (x % 2 == 0)
                img.data[400 * y + x] = 0x0000FF;
            else
                img.data[400 * y + x] = 0xFFFFFF;
            x++;
        }
        y++;
    }

// _______________________________
int        main(void)
{
    t_mlx    mlx;
    t_img    img;
 
    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 300, 300, "title");
    img.img = mlx_xpm_file_to_image(mlx.mlx, "./img/wall_n.xpm", &(img.width), &(img.height));
    img.data = (int *)mlx_get_data_addr(img.img, &(img.bpp), &(img.line_size), &(img.endian));
 
    int y = 0;
    while (y < img.height)
    {
        int x = 0;
        while (x < img.width)
        {
            if (x % 5 == 0)
                img.data[img.width * y + x] = 0x00FF00;
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
    mlx_loop(mlx.mlx);
    return (0);
}
