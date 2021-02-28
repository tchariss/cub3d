/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_card_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:57:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/28 14:25:24 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	void	*dst;

	dst = all->addr + (y * all->line_length + x * (all->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
		// ft_putstr(" ");
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

void ft_to_3d(t_all *all)
{
	// printf("\nСoordinate_x - %i\n", all->x);
	// all->count = 0;
	all->y = 0;
	while (all->y != SCREEN_HEIGHT)
	{
		if (all->y <= ( SCREEN_HEIGHT / 2 ) - ( all->height_wall / 2 ))
		{
			my_mlx_pixel_put(all, all->count, all->y, 0xececf9);
		}
		else if ((all->y > ( SCREEN_HEIGHT / 2 ) - ( all->height_wall / 2 )) && 
		(all->y <= ( SCREEN_HEIGHT / 2 ) + ( all->height_wall / 2 )))
		{
			my_mlx_pixel_put(all, all->count, all->y, 0xFFC0BE); //0xFFC0BE
		}
		else 
		{
			my_mlx_pixel_put(all, all->count, all->y, 0xd2ebd7);
		}
		all->y++;
	}
	all->count++;
	// printf("\nAFTER - Сount - %i\n", all->count);
	// printf("AFTER - Сoordinate_y - %i", all->y);
	//  mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0); // помещает img в окно или рисует изображение внутри
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
	draw_screen(&all);
	// ft_cast_ray(&all);
	
	mlx_loop_hook(all.mlx, &key_process, &all);
	mlx_loop(all.mlx);
	free(&all);
}
