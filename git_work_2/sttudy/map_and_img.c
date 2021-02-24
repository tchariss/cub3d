/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:26:55 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/07 13:28:02 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./minilibx_mms_20200219/mlx.h"

# define width_img 400
# define heig_img 300

// int main()
// {
// 	void *mlx;
// 	void *win;
// 	void *img;
// 	int		width_img;
// 	int 	heig_img;
    
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 1020, 720, "hello, vikos");
// 	img = mlx_xpm_file_to_image(mlx, "./textures/north.xpm", &width_img, &heig_img);
// 	mlx_put_image_to_window(mlx, win, img, 50, 50);
// 	mlx_loop(mlx);
// 	return (0);
// }


typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

int	main(void)
{
	t_mlx	*mlx;
	int		count_w;
	int		count_h;
	t_img	img;

	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, 1020, 720, "A simple example");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, width_img, heig_img);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	count_h = -1;
	while (++count_h < heig_img)
	{
		count_w = -1;
		while (++count_w < width_img)
		{
			if (count_w % 2)
				img.data[count_h * width_img + count_w] = 0xFFFFE0; // белый - желтый
			else
				img.data[count_h * width_img + count_w] = 0x00008B;// синий
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}