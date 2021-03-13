/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:18:00 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/22 18:19:36 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


static int	data_to_bmp(t_all *all, int fd)
{
	int i;

	i = all->width * all->height - 1;
	while (i >= 0)
	{
		write(fd, &all->data[i * all->bpp / 8], 4);
		i--;
	}
	return (1);
}

static void	make_vertical_pixel(t_all *all, int line_cnt, int *e, int f)
{
	char	save;
	int		k;

	k = 3;
	while (k >= 0)
	{
		save = all->data[*e + (line_cnt * all->size_l)];
		all->data[*e + (line_cnt * all->size_l)] =
			all->data[f - k + (line_cnt * all->size_l - 1)];
		all->data[f - k + (line_cnt * all->size_l - 1)] =
			save;
		k--;
		*e = *e + 1;
	}
}

static int	make_vertical_line(t_all *all)
{
	int		line_cnt;
	int		e;
	int		f;

	line_cnt = 0;
	while (line_cnt < all->height)
	{
		e = 0;
		f = all->size_l;
		while (e < f && e != f)
		{
			make_vertical_pixel(all, line_cnt, &e, f);
			f -= 4;
		}
		line_cnt++;
	}
	return (1);
}

static int	make_bmp_header(t_all *all, int fd)
{
	int header_size;
	int plane_nbr;
	int o_count;

	header_size = 40;
	plane_nbr = 1;
	write(fd, &header_size, 4);
	write(fd, &all->width, 4);
	write(fd, &all->height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &all->bpp, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (1);
}

void		create_screenshot(t_all *all, char *filename)
{
	int fd;
	int file_size;
	int first_pix;

	filename = ft_strjoin(filename, ".bmp");
	if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
		exit(EXIT_FAILURE);
	file_size = 14 + 40 + 4 + (all->width * all->height) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	make_bmp_header(all, fd);
	make_vertical_line(all);
	data_to_bmp(all, fd);
	close(fd);
	free(filename);
	exit(EXIT_SUCCESS);
}