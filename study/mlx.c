/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:04:07 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/01 20:17:16 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_mms_20200219/mlx.h"
#include "get_next_line.h"
#include "get_next_line.h"
#include <fcntl.h>

int		cub_1()
{
    void *mlx = 0;
    void *win = 0;
    int x = 0;
    int y = 0;

	mlx = mlx_init();
    win = mlx_new_window(mlx, 1080, 720, "hello, vikos");
    while (y && x)
	{
		if (x == '1' && y == '1')
			mlx_pixel_put(mlx, win, x, y, 0xEDDBFF);
		x++;
		y++;
	}
	mlx_loop(mlx);
	return (0);
}

int		main()
{
	int		fd;
	char	*line;
	char	*lst;

	fd = open("cub.cub", O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{ //количество строк неопределено, потому она добавляются в список, считается 
	// размер и переводится в двумерный массив , пока файл считывается	
		lst = line;
	}
	printf("%s", line);
	free(line);
	return (0);
}
