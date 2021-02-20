/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_card_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:57:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/17 18:59:58 by tchariss         ###   ########.fr       */
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
#define SCREEN_WIDTH 808
#define SCREEN_HEIGHT 648


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
    float   l_2d;
    float   length_real;
    //float   h_y_2d;
    float   h_wall_3d ;
}				t_all;

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	void	*dst;

	dst = all->addr + (y * all->line_length + x * (all->bits_per_pixel / 8));
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

	all->row = 0;
	all->x = 0;
	all->y = 0;
	all->s = (char **)malloc(sizeof(char **) * (size_map())); // x * y + 1 ?
	fd = open("try.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		all->s[all->y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
		all->s[all->y] = line;
		//
		ft_putstr(all->s[all->y]);
		all->y++;
		all->row++;
	}
	all->s[all->y] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
	all->s[all->y] = line;
	ft_putstr(all->s[all->y]);

	all->y++;
	all->row++;
	return (0);
}

void draw_cub(int x, int y, t_all *all, int color)
{
	int x_max = x + PIX_SIZE; // pix_SIZE =32
	int y_max = y + PIX_SIZE; // 100 + 32 -> y_max = 132
	int save_x = x; // изначальной координате х (если 100)
	
	while (y < y_max) // y_max = 132 / y = 100 
	{
		x = save_x; // x = изначальному x
		while (x < x_max) // x = 100
		{
			//my_mlx_pixel_put(all, x, y, color);
			my_mlx_pixel_put(all, x, y, color);
            x++;
		}
		y++;
	}
}

void	ft_cast_ray(t_all *all)
{
	// all->img = mlx_new_image(all->mlx, 808, 648);
	// all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel, &all->line_length, &all->endian);
	//mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100);	
	// all->plr.start = all->plr.dir - M_PI_6; // начало веера луча | /
	// all->plr.end = all->plr.dir + M_PI_6; // конец веера луча \ |
	// float rem_x_p = 0;
	// float rem_y_p = 0;
	printf("\nBEFORE---------------\n\n");
	printf("--X_PLAYER-------x_pl: %f\n", all->plr.x_p);
	printf("---X1-------x1: %f\n", all->x1);
	

	if (all->s[(int)all->plr.y_p / PIX_SIZE][(int)all->plr.x_p / PIX_SIZE] == '1')
	{
		all->plr.x_p = all->x1 ;
		all->plr.y_p = all->y1 ;
	}
	all->x1 = all->plr.x_p;
	all->y1 = all->plr.y_p;
	// rem_x_p = all->plr.x_p;
	// rem_y_p = all->plr.y_p;
	// // // while (all->plr.start <= all->plr.end)
	// // {
	// 	all->x1 = rem_x_p;
	// 	all->y1 = rem_y_p;
	// 	rem_x_p = all->plr.x_p;
	// 	rem_y_p = all->plr.y_p;
	// if (all->s[(int)all->y1 / PIX_SIZE][(int)all->x1 / PIX_SIZE] == '1')
	// {
		
	// }
	while (all->s[(int)all->y1 / PIX_SIZE][(int)all->x1 / PIX_SIZE] != '1') // пока не равно стене, печатаю попиксельно луч
	{
		all->x1 += cos(all->plr.dir);
		all->y1 += sin(all->plr.dir);                      
		my_mlx_pixel_put(all, all->x1, all->y1, 0x22223B);
		// my_mlx_pixel_put(all, all->plr.x_p, all->plr.y_p, 0x22223B);
	}
	// 	all->plr.start = all->plr.start + M_PI_3 / SCREEN_WIDTH;

    //     all->l_2d = PIX_SIZE / 2 * (tan(M_PI_6)); // длина до стены в проекции 2д
    // 	all->length_real = sqrt(pow((all->x1 - rem_x_p),(2)) + pow((all->y1 - rem_y_p),(2))); // длина до стены реальная
    // 	//all->h_y_2d = (PIX_SIZE / all->length_real) * all->l_2d; // высота стены на проекции 2д
    // 	all->h_wall_3d  = (PIX_SIZE / all->length_real) *  all->l_2d; // высота стены реальная 
	// }

	/////////////////////////////////////////////
	//after_draw_screen(all);
	// mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100);
	// after_draw_screen(all);
	// printf("\n----------------------\n");

	// printf("all->l_2d : %f\n", all->l_2d );
	// printf("all->length_real : %f\n", all->length_real );
	// //printf("all->h_y_2d  : %f\n", all->h_y_2d );
	// printf("all->h_wall_3d  : %f\n", all->h_wall_3d );
	
	printf("\n----------------------\n\n");
	printf("ft_castr_ray : \n-----------dir: %f\n", all->plr.dir);
	printf("--X_PLAYER-------x_pl: %f\n", all->plr.x_p);
	printf("---X1-------x1: %f\n", all->x1);
// printf("\n----------------------\n\n");
// 	printf("-----------x1: %f\n", all->x1);
// 	printf("-----------y1: %f\n", all->y1);
}

		

void draw_3d(t_all *all)
{
	while ()
}

void draw_screen(t_all *all) /////////////////////////////////////
{
	// all->img = mlx_new_image(all->mlx, 808, 648);
	// all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel, &all->line_length, &all->endian);
	// void *mlx = 0;
	// void *win = 0;
	int	cor_x = 0;
	int	cor_y = 0;
	// player_2 st;
	// all->plr = &st;
	

	cor_y = 0;
	all->y = 0; // на начало чтения строки 0-ой элемент массива
	while (all->s[all->y] && all->y != all->row) // != NULL 
	{
		all->x = 0; // на начало чтения строки 0-ой элемент массива
		cor_x = 0;
		while (all->s[all->y][all->x] != '\0')
		{
			if (all->s[all->y][all->x] == '1') //[all->x++]
			{	
				draw_cub(cor_x, cor_y, all, 0xD4B8D9); // 0xD4B8D9
			}
			if (all->s[all->y][all->x] == '0')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
			}
			if (all->s[all->y][all->x] == 'N')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
				all->plr.dir = -M_PI_2; // 270 граудсов, но смотрит вверх // M_PI + M_PI_2
				//all->p = all->s[all->y][all->x]; // передаю координаты игроку p, если нахожу N [6][2]
				all->plr.x_p = cor_x + PIX_SIZE / 2; // от центра игрока
				all->plr.y_p = cor_y + PIX_SIZE / 2;
			}
			if (all->s[all->y][all->x] == 'S')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
				all->plr.dir = M_PI_2; // 90 граудсов, но смотрит вниз
				all->plr.x_p = cor_x + PIX_SIZE / 2;
				all->plr.y_p = cor_y + PIX_SIZE / 2;
				// draw_cub(cor_x, cor_y, mlx, win, 0x8E9AAF);
				// my_mlx_pixel_put(mlx, win, cor_x, cor_y, 0x8E9AAF);
			}
			if (all->s[all->y][all->x] == 'W')
			{
				draw_cub(cor_x, cor_y, all, 0xE5E5E5);
				all->plr.dir = M_PI; // влево
				all->plr.x_p = cor_x + PIX_SIZE / 2;
				all->plr.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, all, 0x8E9AAF);
			}
			if (all->s[all->y][all->x] == 'E')
			{
				all->plr.dir = 0;// вправо
				all->plr.x_p = cor_x + PIX_SIZE / 2;
				all->plr.y_p = cor_y + PIX_SIZE / 2;
				draw_cub(cor_x, cor_y, all, 0x8E9AAF);
			}
			all->x++;
			cor_x = cor_x + PIX_SIZE;
		}
		all->y++; // перешагиваю на след строку массива вниз 
		cor_y = cor_y + PIX_SIZE;
	}
	printf("draw_screen: \ndir: %f\n", all->plr.dir);
	printf("x_pl_pos: %f\n", all->plr.x_p);
	printf("y_pl_pos: %f\n", all->plr.y_p);
	 ////////////////////////////////////////////////////////////////////////////////////////////
	//mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100);
	//ft_cast_ray(all);
    
	mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100);
}

int my_close(t_all *img)
{
	free(img);
    exit(0);
}

int	press_key(int keycode, t_all *all) // esc
{
    
	printf("%d\n", keycode);
	
	printf("press_key: \ndir: %f\n", all->plr.dir);
	printf("x_pl_place: %f\n", all->plr.x_p);
	printf("y_pl_place: %f\n", all->plr.y_p);
	//mlx_clear_window (all->mlx, all->win);
	//draw_screen(all);
	// ft_cast_ray(all);
	
	if (keycode == 13) // W
	{
		
		all->plr.y_p--;
		// printf("x_place before keycode: %f\n", all->place_x);
		// all->plr.y_p += sin(all->plr.dir) * 4;
		// all->plr.x_p += cos(all->plr.dir) * 4;
	}
	if (keycode == 1) // S
	{
		//mlx_clear_window (all->mlx, all->win);
		//draw_screen(all);
		all->plr.y_p++;
		
		// all->plr.y_p -= sin(all->plr.dir) * 4;
		// all->plr.x_p -= cos(all->plr.dir) * 4;
	}
	if (keycode == 0) // A
	// 	//all->plr.dir -= 0.1;
		all->plr.x_p--;
	if (keycode == 2) // D
	// 	// all->plr.dir += 0.1;
		all->plr.x_p++;
	if (keycode == 123) // A
		all->plr.dir -= 0.1;
		//all->plr.y_p++;
	if (keycode == 124) // D
		all->plr.dir += 0.1;
	if (keycode == 53)
		exit(0);
	if (keycode == 1L << 17)
	{
		free(all->img);
    	exit(0);
	}
	//draw_screenall;
	//draw_cub_player(pr->x_p, pr->y_p, mlx, win, 0x8E9AAF);

	printf("\n\n--------------------\n");
	printf(": \ndir: %f\n", all->plr.dir);
	printf("x_pl_place: %f\n", all->plr.x_p);
	printf("y_pl_place: %f\n", all->plr.y_p);
	printf("\n\n--------------------\n");

	//mlx_destroy_image(all->mlx, all->img);

	// mlx_clear_window(all->mlx, all->win);
	// draw_screen(all);
    ft_cast_ray(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 100, 100);
	// after_draw_screen(all);
	

	//printf("(x, y): (%f, %f)\n",	x_p,	y_p);
	return (0);
}

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

	//mlx_loop_hook(all->mlx, press_key, &all);
	//ft_cast_ray(&all);
	mlx_hook(all.win, 2, 0, &press_key, &all);
	mlx_hook(all.win, 17, 0L, &my_close, all.img);

	    //    int (void *mlx_ptr, int (*funct_ptr)(), void *param); !!!!! Зациклить действия и не чистить окно
	mlx_loop(all.mlx);
}

