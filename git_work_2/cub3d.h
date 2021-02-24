/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:43:46 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/22 18:42:49 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <math.h>
# define PIX_SIZE 32
# define M_PI_6 0.52359877 //30 градусов
# define M_PI_3 1.04719755 // 60 градусов
# define SCREEN_WIDTH 808
# define SCREEN_HEIGHT 648

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
	char 	**st;
	player_2 plr;
	void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
    float   p_dis; // projection distance или расстояние до проекции
    float   distance_real;
    // float   h_y_2d;
	int w;
	int s;
	int a;
	int d;
	int turn_left;
	int turn_right;
    float height_wall;
	float save_x_p;
	float save_y_p;
}				t_all;

void		my_mlx_pixel_put(t_all *all, int x, int y, int color);
int my_close(t_all *img);
void	ft_putstr(char *s);
int size_map(void);
int		gnl_card(t_all *all);
void draw_cub(int x, int y, t_all *all, int color);
void go_play(t_all *all, int x, int y);
void	ft_cast_ray(t_all *all);
void draw_screen(t_all *all);
int my_close(t_all *img);
int	key_process(t_all *all);
void	draw_again(t_all *all);
int pushback(int keycode, t_all *all);
int press(int keycode, t_all *all);
int	press_key(t_all *all);
int			check_header_name(char *header);

#endif