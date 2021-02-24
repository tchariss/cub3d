/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_card_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:57:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/22 19:21:22 by tchariss         ###   ########.fr       */
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

// void draw_3d(t_all *all)
// {
// 	while ()
// }

int main()
{
	t_all	all;
	int		count_h;
	int		count_w;
	
	all = *(t_all *)ft_calloc(sizeof(t_all), 1);
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "hello, vikos");
	all.img = mlx_new_image(all.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);   // создает новый образ в памяти 
	all.addr = mlx_get_data_addr(all.img, &all.bits_per_pixel, &all.line_length, &all.endian); // возвращает информацию о созданном img
	gnl_card(&all);
	draw_screen(&all);
	ft_cast_ray(&all);

	// mlx_hook(all.win, 2, 1L, &press_key, &all); // &press
	// mlx_hook(all.win, 3, 1L<<1, &pushback, &all);
	// mlx_hook(all.win, 17, 0, &my_close, all.img);

	// printf("%f\n", all.plr.x_p);
	// printf("%f\n", all.plr.y_p);
	mlx_loop_hook(all.mlx, &key_process, &all);
	
	
	    //    int (void *mlx_ptr, int w(*funct_ptr)(), void *param); !!!!! Зациклить действия и не чистить окно
	mlx_loop(all.mlx);
	free(&all);
}
