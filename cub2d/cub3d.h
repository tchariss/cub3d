/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:43:46 by tchariss          #+#    #+#             */
/*   Updated: 2021/03/12 19:17:07 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <math.h>
# include <unistd.h>
# define PIX_SIZE 64
# define M_PI_6 0.52359877 //30 градусов
# define M_PI_3 1.04719755 // 60 градусов
# define SCREEN_WIDTH 808
# define SCREEN_HEIGHT 648

typedef struct			
{
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
	void	*tex_1;
	int		width;
	int		height;
}			t_texture_n;

typedef struct		
{
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
	void	*tex_2;
	int		width;
	int		height;
}			t_texture_w;

typedef struct		
{
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
	void	*tex_3;
	int		width;
	int		height;
}			t_texture_s;


typedef struct		
{
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
	void	*tex_4;
	int		width;
	int		height;
}			t_texture_e;

typedef struct	
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
}				t_player_2;

typedef struct	s_all
{
	void *mlx;
	void *win;
	int		x; // позиция по х, у
	int		y;
	int		p;
	int		row; // столбцы
	float place_y;
	float place_x;
	
	// float	a;    // направление
	// float	fov;  // поле зрение
	char 	**st;
	t_player_2 plr;
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
	int count;
	int y_i;
	t_texture_n	tex_n;
	t_texture_w	tex_w;
	t_texture_s	tex_s;
	t_texture_e	tex_e;
	
	int horiz_n;
	int horiz_s;
	int vert_w;
	int vert_e;
	float i;
	int x_col_tex;
	int y_col_tex;
	float pix_wall;
	// float pix_wall;
}				t_all;

void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
int		my_close(t_all *img);
void	ft_putstr(char *s);
int		size_map(void);
int		gnl_card(t_all *all);
void	draw_cub(int x, int y, t_all *all, int color);
void	go_play(t_all *all, int x, int y);
void	ft_cast_ray(t_all *all);
void	draw_screen(t_all *all);
int		my_close(t_all *img);
int		key_process(t_all *all);
void	draw_again(t_all *all);
int		pushback(int keycode, t_all *all);
int		press(int keycode, t_all *all);
int		press_key(t_all *all);
int		check_header_name(char *header);
void	ft_to_3d(t_all *all);
void 	get_xpm_texture_n(t_all *all);
void 	get_xpm_texture_w(t_all *all);
void 	get_xpm_texture_s(t_all *all);
void 	get_xpm_texture_e(t_all *all);
int		color_tex_1(t_all *all, int x, int y);
int		color_tex_2(t_all *all, int x, int y);
int		color_tex_3(t_all *all, int x, int y);
int		color_tex_4(t_all *all, int x, int y);

#endif