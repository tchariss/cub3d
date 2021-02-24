/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   card_gnl_with_star.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:57:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/13 22:10:42 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./minilibx_mms_20200219/mlx.h"
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include <math.h>
#define PIX_SIZE 32
#define M_PI_6 0.52359877 //30 градусов
#define M_PI_3 1.04719755 // 60 градусов
#define SCREEN_WIDTH
#define SCREEN_HEIGHT


typedef struct	player_1
{
	float		x_p;
	float		y_p;
	float		dir;
	float		start;
	float		end;
//	char	str[3];
	//int		p; // сам игрок
	//float x, y; // позиция по х, у
	//float a;    // направление
	//float fov;  // поле зрение
}				player_2;

typedef struct	all_s
{
	void *mlx;
	void *win;
	int		x; // позиция по х, у
	int		y;
	int		p;
	int		row; // столбцы
	float place_y;
	float place_x;
	
	void	*p_img; 
	int		img_width;
	int		img_height;
	// float	a;    // направление
	// float	fov;  // поле зрение
	char 	**s;
	player_2 plr;
	void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_all;

// void zero_struct(t_all **all)
// {
// 	(*all)->mlx = 0;
// 	(*all)->win = 0;
// 	(*all)->x = 0; // позиция по х, у
// 	(*all)->y = 0;
// 	(*all)->p = 0;
// 	(*all)->row = 0; // столбцы
// 	(*all)->place_y = 0;
// 	(*all)->place_x = 0;

// 	(*all)->p_img = 0; 
// 	(*all)->img_width = 0;
// 	(*all)->img_height = 0;

// 	(*all)->s = NULL;
// 	// (*all)->player_2 plr;
// 	(*all)->img = 0;
//     (*all)->addr = NULL;
//     (*all)->bits_per_pixel = 0;
//     (*all)->line_length = 0;
//     (*all)->endian = 0;
// 	(*all)->plr.x_p = 0;
// 	(*all)->plr.y_p = 0;
// 	(*all)->plr.dir = 0;
// 	(*all)->plr.start = 0;
// 	(*all)->plr.end = 0;
// }

// void			param_init(player_2 *par)
// {
// 	x_p = 3;
// 	y_p = 4;
// 	str[0] = 'a';
// 	str[1] = 'b';
// 	str[2] = '\0';
// }



void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	void	*dst;

	dst = (*all).addr + (y * (*all).line_length + x * ((*all).bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void     close_my(int keycode, void *mlx, void *win)
{
    mlx_destroy_window(mlx, win);
}

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
		i = i + ft_strlen(line);
	}
	i++;
	return (i);
}

int		gnl_card(t_all *all)
{
	char	*line;
	int		fd;

	(*all).row = 0;
	(*all).x = 0;
	(*all).y = 0;
	(*all).s = (char **)malloc(sizeof(char **) * (size_map())); // x * y + 1 ?
	fd = open("try.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		(*all).s[(*all).y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
		(*all).s[(*all).y] = line;
		//
		ft_putstr((*all).s[(*all).y]);
		(*all).y++;
		(*all).row++;
	}
	(*all).s[(*all).y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
	(*all).s[(*all).y] = line;
	ft_putstr((*all).s[(*all).y]);

	(*all).y++;
	(*all).row++;
	return (0);
}

void draw_cub(int x, int y, t_all **all, int color)
{
	// char *ad
	// char ad;
	// &ad = all;
	
	int x_max = x + PIX_SIZE; // pix_SIZE =32
	int y_max = y + PIX_SIZE; // 100 + 32 -> y_max = 132
	int save_x = x; // изначальной координате х (если 100)
	
	while (y < y_max) // y_max = 132 / y = 100 
	{
		x = save_x; // x = изначальному x
		while (x < x_max) // x = 100
		{
			//my_mlx_pixel_put(all, x, y, color);
			my_mlx_pixel_put(*all, x, y, color);
            x++;
		}
		y++;
	}
}

void after_draw_screen(t_all **all) /////////////////////////////////////
{
	// (*all)->img = mlx_new_image((*all)->mlx, 808, 648);
	// (*all)->addr = mlx_get_data_addr((*all)->img, &(*all)->bits_per_pixel, &(*all)->line_length, &(*all)->endian);
	// void *mlx = 0;
	// void *win = 0;
	int	cor_x = 0;
	int	cor_y = 0;
	// player_2 st;
	// (*all)->plr = &st;
	
	//param_init(&st);
	// (*all)->mlx = mlx_init();
	// (*all)->win = mlx_new_window((*all)->mlx, 1020, 720, "hello, vikos");
	//(*all)->img = mlx_xpm_file_to_image(mlx, "./textures/north.xpm", &(*all)->img_width, &(*all)->img_height);
	cor_y = 0;
	(*all)->y = 0; // на начало чтения строки 0-ой элемент массива
	while ((*all)->s[(*all)->y] && (*all)->y != (*all)->row) // != NULL 
	{
		(*all)->x = 0; // на начало чтения строки 0-ой элемент массива
		cor_x = 0;
		while ((*all)->s[(*all)->y][(*all)->x] != '\0')
		{
			if ((*all)->s[(*all)->y][(*all)->x] == '1') //[(*all)->x++]
			{	
				draw_cub(cor_x, cor_y, all, 0xD4B8D9); // 0xD4B8D9
			}
			if ((*all)->s[(*all)->y][(*all)->x] == '0')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
			}
			if ((*all)->s[(*all)->y][(*all)->x] == 'N')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
				(*all)->plr.dir = -M_PI_2; // 270 граудсов, но смотрит вверх // M_PI + M_PI_2
				//(*all)->p = (*all)->s[(*all)->y][(*all)->x]; // передаю координаты игроку p, если нахожу N [6][2]
				(*all)->plr.x_p = cor_x + PIX_SIZE / 2; // от центра игрока
				(*all)->plr.y_p = cor_y + PIX_SIZE / 2;
			}
			if ((*all)->s[(*all)->y][(*all)->x] == 'S')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
				(*all)->plr.dir = M_PI_2; // 90 граудсов, но смотрит вниз
				(*all)->plr.x_p = cor_x + PIX_SIZE / 2;
				(*all)->plr.y_p = cor_y + PIX_SIZE / 2;
				// draw_cub(cor_x, cor_y, mlx, win, 0x8E9AAF);
				// my_mlx_pixel_put(mlx, win, cor_x, cor_y, 0x8E9AAF);
			}
			if ((*all)->s[(*all)->y][(*all)->x] == 'W')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
				(*all)->plr.dir = M_PI; // влево
				(*all)->plr.x_p = cor_x + PIX_SIZE / 2;
				(*all)->plr.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, all, 0x8E9AAF);
			}
			if ((*all)->s[(*all)->y][(*all)->x] == 'E')
			{
				(*all)->plr.dir = 0;// вправо
				(*all)->plr.x_p = cor_x + PIX_SIZE / 2;
				(*all)->plr.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, all, 0x8E9AAF);
			}
			(*all)->x++;
			cor_x = cor_x + PIX_SIZE;
		}
		(*all)->y++; // перешагиваю на след строку массива вниз 
		cor_y = cor_y + PIX_SIZE;
	}
	printf("AFTER___________________draw_screen: \ndir: %f\n", (*all)->plr.dir);
	printf("x_pl_pos: %f\n", (*all)->plr.x_p);
	printf("y_pl_pos: %f\n", (*all)->plr.y_p);
	 ////////////////////////////////////////////////////////////////////////////////////////////
	//mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img, 100, 100);

}



void	ft_cast_ray(t_all **all)
{
	// (*all).img = mlx_new_image((*all).mlx, 808, 648);
	// (*all).addr = mlx_get_data_addr((*all).img, &(*all).bits_per_pixel, &(*all).line_length, &(*all).endian);
	//mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img, 100, 100);	
	(*all)->plr.start = (*all)->plr.dir - M_PI_6; // начало веера луча | /
	(*all)->plr.end = (*all)->plr.dir + M_PI_6; // конец веера луча \ |
	float rem_x_p = 0;
	float rem_y_p = 0;
	float save_pl_x = (*all)->plr.x_p;
	float save_pl_y = (*all)->plr.y_p;
	
	// (*all).place_x = 0;
	// (*all).place_y = 0;
	// (*all).place_x = (*all).plr.x_p;
	// (*all).place_y = (*all).plr.y_p;
	rem_x_p = (*all)->plr.x_p;
	rem_y_p = (*all)->plr.y_p;
	while ((*all)->plr.start <= (*all)->plr.end)
	{
		save_pl_x = rem_x_p;
		save_pl_y = rem_y_p;
		// rem_x_p = (*all).plr.x_p;
		// rem_y_p = (*all).plr.y_p;
		while ((*all)->s[(int)save_pl_y / PIX_SIZE][(int)save_pl_x / PIX_SIZE] != '1') // пока не равно стене, печатаю попиксельно луч
		{
			save_pl_x += cos((*all)->plr.start);
			save_pl_y += sin((*all)->plr.start);                      
			my_mlx_pixel_put(*all, save_pl_x, save_pl_y, 0x22223B);
			// my_mlx_pixel_put(all, (*all).plr.x_p, (*all).plr.y_p, 0x22223B);
		}
	//(*all).plr.dir = (*all).plr.dir + 0.5; // кривой луч
		(*all)->plr.start = (*all)->plr.start + M_PI_3 / 20;
	}
	/////////////////////////////////////////////
	//after_draw_screen(all);
	// mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img, 100, 100);
	// after_draw_screen(all);
	printf("-------------ft_castr_ray : \ndir: %f\n", (*all)->plr.dir);
	printf("-------------x_pl: %f\n", (*all)->plr.x_p);
	printf("-------------y_pl: %f\n", (*all)->plr.y_p);
}




void draw_screen(t_all **all) /////////////////////////////////////
{
	// (*all)->img = mlx_new_image((*all)->mlx, 808, 648);
	// (*all)->addr = mlx_get_data_addr((*all)->img, &(*all)->bits_per_pixel, &(*all)->line_length, &(*all)->endian);
	// void *mlx = 0;
	// void *win = 0;
	int	cor_x = 0;
	int	cor_y = 0;
	// player_2 st;
	// (*all)->plr = &st;
	
	//param_init(&st);
	// (*all)->mlx = mlx_init();
	// (*all)->win = mlx_new_window((*all)->mlx, 1020, 720, "hello, vikos");
	//(*all)->img = mlx_xpm_file_to_image(mlx, "./textures/north.xpm", &(*all)->img_width, &(*all)->img_height);
	cor_y = 0;
	(*all)->y = 0; // на начало чтения строки 0-ой элемент массива
	while ((*all)->s[(*all)->y] && (*all)->y != (*all)->row) // != NULL 
	{
		(*all)->x = 0; // на начало чтения строки 0-ой элемент массива
		cor_x = 0;
		while ((*all)->s[(*all)->y][(*all)->x] != '\0')
		{
			if ((*all)->s[(*all)->y][(*all)->x] == '1') //[(*all)->x++]
			{	
				draw_cub(cor_x, cor_y, all, 0xD4B8D9); // 0xD4B8D9
			}
			if ((*all)->s[(*all)->y][(*all)->x] == '0')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
			}
			if ((*all)->s[(*all)->y][(*all)->x] == 'N')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
				(*all)->plr.dir = -M_PI_2; // 270 граудсов, но смотрит вверх // M_PI + M_PI_2
				//(*all)->p = (*all)->s[(*all)->y][(*all)->x]; // передаю координаты игроку p, если нахожу N [6][2]
				(*all)->plr.x_p = cor_x + PIX_SIZE / 2; // от центра игрока
				(*all)->plr.y_p = cor_y + PIX_SIZE / 2;
			}
			if ((*all)->s[(*all)->y][(*all)->x] == 'S')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
				(*all)->plr.dir = M_PI_2; // 90 граудсов, но смотрит вниз
				(*all)->plr.x_p = cor_x + PIX_SIZE / 2;
				(*all)->plr.y_p = cor_y + PIX_SIZE / 2;
				// draw_cub(cor_x, cor_y, mlx, win, 0x8E9AAF);
				// my_mlx_pixel_put(mlx, win, cor_x, cor_y, 0x8E9AAF);
			}
			if ((*all)->s[(*all)->y][(*all)->x] == 'W')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
				(*all)->plr.dir = M_PI; // влево
				(*all)->plr.x_p = cor_x + PIX_SIZE / 2;
				(*all)->plr.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, all, 0x8E9AAF);
			}
			if ((*all)->s[(*all)->y][(*all)->x] == 'E')
			{
				(*all)->plr.dir = 0;// вправо
				(*all)->plr.x_p = cor_x + PIX_SIZE / 2;
				(*all)->plr.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, all, 0x8E9AAF);
			}
			(*all)->x++;
			cor_x = cor_x + PIX_SIZE;
		}
		(*all)->y++; // перешагиваю на след строку массива вниз 
		cor_y = cor_y + PIX_SIZE;
	}
	printf("draw_screen: \ndir: %f\n", (*all)->plr.dir);
	printf("x_pl_pos: %f\n", (*all)->plr.x_p);
	printf("y_pl_pos: %f\n", (*all)->plr.y_p);
	 ////////////////////////////////////////////////////////////////////////////////////////////
	//mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img, 100, 100);
	ft_cast_ray(all);
	mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img, 100, 100);
}

int my_close(t_all *img)
{
	free(img);
    exit(0);
}

int	press_key(int keycode, t_all **all) // esc
{
	
	// player_2 st;
	// (*all).plr = &st;
	//printf("%s\n","hello");
	//(*all)->plr.x_p = 320.000000;
	// (*all)->plr.y_p = 220.861328;
	printf("%d\n", keycode);
	
	printf("press_key: \ndir: %f\n", (*all)->plr.dir);
	printf("x_pl_place: %f\n", (*all)->plr.x_p);
	printf("y_pl_place: %f\n", (*all)->plr.y_p);
	//mlx_clear_window ((*all)->mlx, (*all)->win);
	//draw_screen(all);
	// ft_cast_ray(all);
	
	if (keycode == 13) // W
	{
		
		(*all)->plr.y_p--;
		// printf("x_place before keycode: %f\n", (*all)->place_x);
		// (*all).plr.y_p += sin((*all).plr.dir) * 4;
		// (*all).plr.x_p += cos((*all).plr.dir) * 4;
	}
	// 	//printf("%s","hello");
	// 	//(*all).plr.x_p++;
	if (keycode == 1) // S
	{
		//mlx_clear_window ((*all)->mlx, (*all)->win);
		//draw_screen(all);
		(*all)->plr.y_p++;
		
	// 	// (*all).plr.y_p -= sin((*all).plr.dir) * 4;
	// 	// (*all).plr.x_p -= cos((*all).plr.dir) * 4;
	}
	if (keycode == 0) // A
	// 	//(*all).plr.dir -= 0.1;
		(*all)->plr.x_p--;
	if (keycode == 2) // D
	// 	// (*all).plr.dir += 0.1;
		(*all)->plr.x_p++;
	if (keycode == 123) // A
		(*all)->plr.dir -= 0.1;
		//(*all).plr.y_p++;
	if (keycode == 124) // D
		(*all)->plr.dir += 0.1;
	if (keycode == 53)
		exit(0);
	if (keycode == 1L << 17)
	{
		free((*all)->img);
    	exit(0);
	}
	//draw_screen(*all);
	//draw_cub_player(pr->x_p, pr->y_p, mlx, win, 0x8E9AAF);

	printf("\n\n--------------------\n");
	printf(": \ndir: %f\n", (*all)->plr.dir);
	printf("x_pl_place: %f\n", (*all)->plr.x_p);
	printf("y_pl_place: %f\n", (*all)->plr.y_p);
	printf("\n\n--------------------\n");

	//mlx_destroy_image((*all)->mlx, (*all)->img);
	//draw_screen(all);
	mlx_clear_window((*all)->mlx, (*all)->win);
	ft_cast_ray(all);
	mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img, 100, 100);
	// after_draw_screen(all);
	// ft_cast_ray(all);

	//printf("(x, y): (%f, %f)\n",	x_p,	y_p);
	return (0);
}

int main()
{
	t_all	*all;
	
	all = (t_all *)ft_calloc(sizeof(t_all), 1);
	(*all).mlx = mlx_init();
	(*all).win = mlx_new_window((*all).mlx, 808, 648, "hello, vikos");
	(*all).img = mlx_new_image((*all).mlx, 808, 648);
	(*all).addr = mlx_get_data_addr((*all).img, &(*all).bits_per_pixel, &(*all).line_length, &(*all).endian);
	gnl_card(all);
	draw_screen(&all);
	//ft_cast_ray(&all);
	// printf("x: %f\n", (*all)->plr.x_p);
	// printf("y: %f\n", (*all)->plr.y_p);
	//mlx_loop_hook((*all).mlx, press_key, &all);
	//ft_cast_ray(&all);
	mlx_hook((*all).win, 2, 0, &press_key, &all);
	mlx_hook((*all).win, 17, 0L, &my_close, (*all).img);
	// mlx_put_image_to_window((*all).mlx, (*all).win, (*all).img, 100, 100);
	    //    int (void *mlx_ptr, int (*funct_ptr)(), void *param); !!!!! Зациклить действия и не чистить окно
	mlx_loop((*all).mlx);
}
//    