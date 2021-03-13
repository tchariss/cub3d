/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_card_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:57:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/03/13 11:50:53 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->addr + (y * all->line_length + x * (all->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
// Функция рисует пиксель в плоскости (х, у) координат окна с заданным цветом.
// (0, 0) - верхний левый угол (x - правое значение, y - нижнее значение)

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1 , s, ft_strlen(s));
	write(1 , "\n", 1);
}

int size_map(void)
{
	char	*line;
	int		fd;
	int		i;
	
	i = 0;
	fd = open("try.cub", O_RDONLY);
	while(get_next_line(fd, &line) > 0)
	{
		i = i + ft_strlen(line + 1);
	}
	i++;
	return (i);
}

int		gnl_card(t_all *all)
{
	char	*line;
	int		fd;

	all->row = 0;
	all->x = 0;
	all->y = 0;
	all->st = (char **)malloc(sizeof(char **) * (size_map())); // x * y + 1 ?
	fd = open("try.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		all->st[all->y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
		all->st[all->y] = line;
		ft_putstr(all->st[all->y]);
		all->y++;
		all->row++;
	}
	all->st[all->y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
	all->st[all->y] = line;
	ft_putstr(all->st[all->y]);
	all->y++;
	all->row++;
	return (0);
}

void get_xpm_texture_n(t_all *all)
{
	all->tex_n.tex_1 = mlx_xpm_file_to_image(all->mlx, "./textures/sleep_pig.xpm", &all->tex_n.width, &all->tex_n.height);
	all->tex_n.addr = mlx_get_data_addr(all->tex_n.tex_1, &all->tex_n.bits_per_pixel, &all->tex_n.line_length, &all->tex_n.endian);
} // south

void get_xpm_texture_w(t_all *all)
{
	all->tex_w.tex_2 = mlx_xpm_file_to_image(all->mlx, "./textures/pig.xpm", &all->tex_w.width, &all->tex_w.height);
	all->tex_w.addr = mlx_get_data_addr(all->tex_w.tex_2, &all->tex_w.bits_per_pixel, &all->tex_w.line_length, &all->tex_w.endian);
}

void get_xpm_texture_s(t_all *all)
{
	all->tex_s.tex_3 = mlx_xpm_file_to_image(all->mlx, "./textures/cat.xpm", &all->tex_s.width, &all->tex_s.height);
	all->tex_s.addr = mlx_get_data_addr(all->tex_s.tex_3, &all->tex_s.bits_per_pixel, &all->tex_s.line_length, &all->tex_s.endian);
}

void get_xpm_texture_e(t_all *all)
{
	all->tex_e.tex_4 = mlx_xpm_file_to_image(all->mlx, "./textures/mouse.xpm", &all->tex_e.width, &all->tex_e.height);
	all->tex_e.addr = mlx_get_data_addr(all->tex_e.tex_4, &all->tex_e.bits_per_pixel, &all->tex_e.line_length, &all->tex_e.endian);
}

int		color_tex_4(t_all *all, int x, int y)
{
	char *dst;

	dst = all->tex_e.addr + (y * all->tex_e.line_length + x * (all->tex_e.bits_per_pixel / 8));
	// if (y != 64 && x != 64)
	// all->x_col_tex_e = x;
	return (*(unsigned int *)dst);
}

int		color_tex_3(t_all *all, int x, int y)
{
	char *dst;

	dst = all->tex_s.addr + (y * all->tex_s.line_length + x * (all->tex_s.bits_per_pixel / 8));
	// if (y != 64 && x != 64)
	// all->x_col_tex_e = x;
	return (*(unsigned int *)dst);
}

int		color_tex_2(t_all *all, int x, int y)
{
	char *dst;

	dst = all->tex_w.addr + (y * all->tex_w.line_length + x * (all->tex_w.bits_per_pixel / 8));
	// if (y != 64 && x != 64)
	// all->x_col_tex_e = x;
	return (*(unsigned int *)dst);
}

int		color_tex_1(t_all *all, int x, int y)
{
	char *dst;

	dst = all->tex_n.addr + (y * all->tex_n.line_length + x * (all->tex_n.bits_per_pixel / 8));
	// if (y != 64 && x != 64)
	// all->x_col_tex = x;
	return (*(int *)dst);
}

void ft_to_3d(t_all *all)
{
	float top_wall = (float)(SCREEN_HEIGHT / 2) - (all->height_wall / 2.0);
	float bottom_wall = (float)(SCREEN_HEIGHT / 2) + (all->height_wall / 2.0);
	// --------------------------------------
	all->y = 0;
	int color = 0;
	float step = 1 * (all->tex_n.height / all->height_wall);
	// ------------------------------------
	// all->i = all->i + step;
	// float tex_x = all->tex.height;
	// printf("pix_wall - %i\n", (int)(all->pix_wall));
	if (all->pix_wall == 0 && all->x == 0)
	{
		printf("addad");
		all->pix_wall = all->pix_wall;
	}
	else 
		all->pix_wall = 0.0;
	// printf("1 - pix_wall - %i\n", (int)(all->pix_wall));
	while (all->y < SCREEN_HEIGHT)
	{
		// float step = (float)(all->tex.height / all->height_wall);
		if (all->y <= top_wall)
		{
			my_mlx_pixel_put(all, all->count, all->y, 0xd2ecf9);
			// all->y++;
		}
		else if (all->y <= bottom_wall)  //  мои стены
		{
			if (all->st[((int)all->save_y_p + 1)/ PIX_SIZE][((int)all->save_x_p + 1) / PIX_SIZE] == '1' && 
			all->st[((int)all->save_y_p - 1)/ PIX_SIZE][((int)all->save_x_p + 1) / PIX_SIZE] != '1')
			{
				color = color_tex_1(all, (all->x_col_tex % PIX_SIZE), all->pix_wall);
				my_mlx_pixel_put(all, all->count, all->y, color);
				// printf("pix_wall - %i\n", (int)(all->pix_wall));
				all->pix_wall += step;
				
				// printf ("\n----------count - %i\n ", all->count);
				// my_mlx_pixel_put(all, all->count, all->y, 0x0081ff); // голубой
			// 	// all->pix_wall += step;
			// 	all->y++;
			}
			else if (all->st[((int)all->save_y_p - 1 )/ PIX_SIZE][((int)all->save_x_p - 1) / PIX_SIZE] == '1' && 
			all->st[((int)all->save_y_p + 1)/ PIX_SIZE][((int)all->save_x_p - 1) / PIX_SIZE] != '1')
			{
				// printf("pix_wall - %i\n", (int)(all->pix_wall));
				color = color_tex_2(all, (all->x_col_tex % PIX_SIZE), all->pix_wall);
				my_mlx_pixel_put(all, all->count, all->y, color); //фиолетовый //0xcc81ff
				// printf("pix_wall - %i\n", (int)(all->pix_wall));
				all->pix_wall += step;
				// all->pix_wall += step;
				// printf("count  - %i\n", all->count);
				// printf("y - %i\n", all->y);	
			}
			else if (all->st[((int)all->save_y_p - 1 )/ PIX_SIZE][((int)all->save_x_p + 1) / PIX_SIZE] == '1')
			{
				color = color_tex_3(all, (all->y_col_tex % PIX_SIZE), all->pix_wall);
				my_mlx_pixel_put(all, all->count, all->y, color); //фиолетовый //0xcc81ff
				all->pix_wall += step;
			}
				
			else if (all->st[((int)all->save_y_p + 1)/ PIX_SIZE][((int)all->save_x_p - 1) / PIX_SIZE] == '1')
			{	
				color = color_tex_4(all, (all->y_col_tex % PIX_SIZE), all->pix_wall);
				my_mlx_pixel_put(all, all->count, all->y, color); //фиолетовый //0xcc81ff
				all->pix_wall += step;
				// printf("count  - %i\n", all->count);
				// printf("y - %i\n", all->y);	
			}
			// // 	my_mlx_pixel_put(all, all->count, all->y, 0xFFC0BE); //0xFFC0BE
		}
		else //(all->y < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(all, all->count, all->y, 0xc4f9c5);
		}
		all->y++;	
		// con++;
	} ////////////  отрисовала одну полоску -≥ выхожу из цикла /////////////
	// printf("2 - pix_wall - %i\n", (int)(all->pix_wall));
	// printf("pix_wall_2 - %i\n", (int)(pix_wall_2));
	// printf("tex_x_2 - %i\n", all->x_col_tex_2);
	all->count++;
}

int main()
{
	t_all	all;
	
	all = *(t_all *)ft_calloc(sizeof(t_all), 1);
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "hello, vikos");
	all.img = mlx_new_image(all.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);   // создает новый образ в памяти 
	all.addr = mlx_get_data_addr(all.img, &all.bits_per_pixel, &all.line_length, &all.endian); // возвращает информацию о созданном img
	gnl_card(&all);
	get_xpm_texture_n(&all);
	get_xpm_texture_e(&all);
	get_xpm_texture_s(&all);
	get_xpm_texture_w(&all);
	
	// get_xpm_texture_s(&all);
	// get_xpm_texture_e(&all);
	draw_screen(&all);
	// ft_cast_ray(&all);
	mlx_loop_hook(all.mlx, &key_process, &all);
	mlx_loop(all.mlx);
	free(&all);
}

// if ((int)all->save_x_p % 64 > 0 && (int)all->save_x_p % 64 < 63 && (int)all->save_y_p % 64 == 63 )
				
			// 	my_mlx_pixel_put(all, all->count, all->y, 0x0081ff); // голубой
			// 	// pix_wall += step;
			// else if ((int)all->save_x_p % 64 > 0 && (int)all->save_x_p % 64 < 63 && (int)all->save_y_p % 64 == 0)
			
			// {
			// 	// pix_wall = 0.0;
			// 	// pix_wall = all->tex.height / all->height_wall;, 
			// 	// while (pix_wall <= 1.0)	
			// 	color = color_tex(all, all->i, pix_wall);
			// 	//printf("save - %f\n", all->save_x_p);
			// 	my_mlx_pixel_put(all, all->count, all->y, color);
			// 	// printf("pix_wall - %i\n", (int)(pix_wall));
			// 	pix_wall += step;
			// 	// printf("pix_wall - %f\n", pix_wall);
			// 	// printf("-------------\n");
				
			// 	// 	pix_wall = pix_wall + (all->tex.height / all->height_wall);
			// 	// }
			// }
			//  // south
			// else if ((int)all->save_y_p % 64 > 0 && (int)all->save_y_p % 64 < 63 && (int)all->save_x_p % 64 == 63)
			// 	my_mlx_pixel_put(all, all->count, all->y, 0xcc81ff); //фиолетовый
			// 	// pix_wall += step;
			
				
			// else if ((int)all->save_y_p % 64 > 0 && (int)all->save_y_p % 64 < 63 && (int)all->save_x_p % 64 == 0)
				
			// 	my_mlx_pixel_put(all, all->count, all->y, 0xffb27d); // светло-оранжевый
			// 	// pix_wall += step;

				
			// else
			// 	my_mlx_pixel_put(all, all->count, all->y, 0xFFC0BE); //0xFFC0BE
			// // save_wall_y++;




// void ft_to_3d(t_all *all)
// {
// 	float top_wall = (float)(SCREEN_HEIGHT / 2) - (all->height_wall / 2.0);
// 	float bottom_wall = (float)(SCREEN_HEIGHT / 2) + (all->height_wall / 2.0);
	
// 	all->y = 0;
// 	all->tex.y_tex = 0;
// 	float pix_wall = 0.0;
// 	int color = 0;
// 	// printf("i - %f\n", all->i);
// 	float step = 1 * (all->tex.height / all->height_wall) ;
// 	// all->i = all->i + step;
// 	// float tex_x = all->tex.height;
// 	int con = 0;
// 	while (all->y < SCREEN_HEIGHT)
// 	{
// 		// pix_wall = 0.0;
// 		// float step = (float)(all->tex.height / all->height_wall);
// 		if (all->y <= top_wall)
// 		{
// 			my_mlx_pixel_put(all, all->count, all->y, 0xd2ecf9);
// 		}
// 		else if (all->y <= bottom_wall)  //  мои стены
// 		{
// 			if (all->st[((int)all->save_y_p + 1)/ PIX_SIZE][((int)all->save_x_p + 1) / PIX_SIZE] == '1' && 
// 			all->st[((int)all->save_y_p - 1)/ PIX_SIZE][((int)all->save_x_p + 1) / PIX_SIZE] != '1'){
				
// 				my_mlx_pixel_put(all, all->count, all->y, 0x0081ff); // голубой
// 				// pix_wall += step;
// 			}
// 			else if (all->st[((int)all->save_y_p - 1 )/ PIX_SIZE][((int)all->save_x_p - 1) / PIX_SIZE] == '1' && 
// 			all->st[((int)all->save_y_p + 1)/ PIX_SIZE][((int)all->save_x_p - 1) / PIX_SIZE] != '1')
// 			{
// 				// pix_wall = 0.0;
// 				// pix_wall = all->tex.height / all->height_wall;, 
// 				// while (pix_wall <= 1.0)	
// 				color = color_tex(all, (int)pix_wall);
// 				//printf("save - %f\n", all->save_x_p);
// 					// if ((int)all->i < 64)
// 				my_mlx_pixel_put(all, all->count, all->y, color);
// 				// printf("pix_wall - %i\n", (int)(pix_wall));
// 				pix_wall += step;
// 				// printf("pix_wall - %f\n", pix_wall);
// 				// printf("pix_wall - %f\n", pix_wall);
// 				// printf("-------------\n");
// 				// printf("i - %f\n", all->i);
// 				// 	pix_wall = pix_wall + (all->tex.height / all->height_wall);
// 				// }
// 			}
// 			else if (all->st[((int)all->save_y_p - 1 )/ PIX_SIZE][((int)all->save_x_p + 1) / PIX_SIZE] == '1'){
				
// 				my_mlx_pixel_put(all, all->count, all->y, 0xcc81ff); //фиолетовый
// 				// pix_wall += step;
// 			}
				
// 			else if (all->st[((int)all->save_y_p + 1)/ PIX_SIZE][((int)all->save_x_p - 1) / PIX_SIZE] == '1'){
				
// 				my_mlx_pixel_put(all, all->count, all->y, 0xffb27d); // светло-оранжевый
// 				// pix_wall += step;
// 			}
// 			// else
// 			// 	my_mlx_pixel_put(all, all->count, all->y, 0xFFC0BE); //0xFFC0BE
// 			// save_wall_y++;
// 			con++;
// 		}
// 		else 
// 		{
// 			my_mlx_pixel_put(all, all->count, all->y, 0xadf7ae);
// 		}
// 		all->y++;
// 	} ////////////  отрисовала одну полоску -≥ выхожу из цикла /////////////
	
// 	// if (con >= 279)
// 	// all->i = 64. ?
// 	// all->i += step;
// 	// else if ((int)all->i > 64) // конец текстуры , то я зануляю i(x) и иду снова по текстуре до 64
// 	// {
// 	// 	all->i += 0.0;
// 	// 	all->i += step;
// 	// }
// 	// if (all->x_col_tex / 64 == 1)
// 		// printf("all->save_x_p - %f\n", all->save_x_p);
// 	// else if ((all->x_col_tex / 64 != 1))
// 	// 	printf("-----");

		
// 	// if (all->i < 64)
// 		// all->i = 0.0;
// 	// else
// 		// all->i += step;
// 	// printf(" y достиг ширины кэрана, новый х ");
	
// 	// printf("i - %f\n", all->i);
// 	// all->i += step;
// 	// printf("i - %f\n", all->i);

// 	all->count++;

// }
