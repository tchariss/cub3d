/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:32:53 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/28 12:51:55 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// (floodFill(int plr_x,int plr_y,int oldcolor,int newcolor))
// flood_fill -> parser card
void flood_fill(int x, int y, int old_color, int new_color)
{ // new _color -> на что поменяется
	if (all->st[y][x] == ' ' || all->st[y][x] == new_color) // if there is no wall or if i haven't been there
		return ("error");                                              // already go back
	if (st[y][x]] != old_color) // if it's not new_color go back
		return;
	
	all->st[x][y] = new_color; // mark the point so that I know if I passed through it. 

	flood_fill(x + 1, y + 1, old_color, new_color);  // then i can either go south
	flood_fill(x + 1, y - 1, old_color, new_color);  // or north
	flood_fill(x - 1, y + 1, old_color, new_color);  // or east
	flood_fill(x - 1, y - 1, old_color, new_color);  // or west
	flood_fill(x + 1, y, old_color, new_color);
	flood_fill(x - 1, y, old_color, new_color);
	flood_fill(x, y + 1, old_color, new_color);
	flood_fill(x, y - 1, old_color, new_color);
	return;
}
// int			treat_description(char *file_name, t_info *info)
// {
//     int		fd;
//     int		gnl_return;

//     if (!check_file_name(file_name))
//         return (-1);
//     if (!(fd = open(file_name, O_RDONLY)))
//         return (-1);
//     while ((gnl_return = get_next_line(fd, &line)) >= 0)
//     {
//         parse_line(line, info, gnl_return);
//         free(line);
//     }
//     close(fd);
//     return (1);
// }

// int			is_space(char c)
// {
// 	if ((c >= 9 && c <= 13) || c == 32)
// 		return (1);
// 	else
// 		return (-1);
// }

// int			config_resolution(char *line)
// {
// 	int		i;
// 	int		x;
// 	int		y;

// 	i = 0;
// 	x = 0;
// 	y = 0;
// 	while (is_space(line[i]))
// 		i++;
// 	while (ft_isdigit(line[i]))
// 	{
// 		x = (x * 10) + (line[i] - '0');
// 		i++;
// 	}
// 	while (is_space(line[i]))
// 		i++;
// 	while (ft_isdigit(line[i]))
// 	{
// 		y = (y * 10) + (line[i] - '0');
// 		i++;
// 	}
// 	if (line[i] != '\0')
// 		return (-1);
// 	else
// 	{
// 		info->window->width = x;
// 		info->window->height = y;
// 	}
// 	return (1);
// }

// int			config_path(int index, char *line)
// {
// 	int		start;
// 	int		end;
// 	char	*path;

// 	start = 0;
// 	while (is_space(line[start]))
// 		start++;
// 	end = ft_strlen(line);
// 	path = ft_substr(line, start, end - start);
// 	if (!path || !file_exists(path))
// 		return (print_error("Invalid Path"));
// 	info->path[index] = path;
// 	return (1);
// }

// int					config_color(char location, char *line)
// {
// 	int				i;
// 	int				r;
// 	int				g;
// 	int				b;
// 	int             new_color;

// 	i = 0;
// 	while (is_space(line[i]))
// 		i++;
// 	while (line[i] && ft_isdigit(line[i]))
// 	{
// 		r = r * 10 + (line[i] - '0');
// 		i++;
// 	}
// 	i++;
// 	while (line[i] && ft_isdigit(line[i]))
// 	{
// 		g = g * 10 + (line[i] - '0');
// 		i++;
// 	}
// 	i++;
// 	while (line[i] && ft_isdigit(line[i]))
// 	{
// 		b = b * 10 + (line[i] - '0');
// 		i++;
// 	}
// 	color = (r * 256 * 256) + (g * 256) + b;
// 	if (location == 'F')
// 		info->floor_colr = new_color;
// 	else if (location == 'C')
// 		info->ceiling_color = new_color;
// 	return (1);
// }

// int			is_type_identifier(char a, char b, char *line)
// {
// 	if ((a == 'R' || a == 'S' || a == 'F' || a == 'C') && is_space(b))
// 	{
// 		if (a == 'R')
// 			config_resolution(line + 1);
// 		else if (a == 'S')
// 			config_path(4, line + 1);
// 		else 
// 			config_color(a, line + 1);
// 	}
// 	else if (a == 'N' && b == 'O')
// 		config_path(0, line + 2);
// 	else if (a == 'S' && b == 'O')
// 		config_path(1, line + 2);
// 	else if (a == 'W' && b == 'E')
// 		config_path(2, line + 2);
// 	else if (a == 'E' && b == 'A')
// 		config_path(3, line + 2);
// 	else
// 		return (-1);
// 	return (0);
// }

// int			is_map_character(char c)
// {
// 	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || 
// 			c == 'W' || c == 'E')
// 		return (1);
// 	return (0);
// }

// int				save_map(char *line, int gnl_return)
// {
// 	static char	**save;
// 	char		*tmp;
// 	int			line_len;

// 	line_len = ft_strlen(line);
// 	tmp = *save;
// 	*save = ft_strjoin(*save, line);
// 	free(tmp);
// 	if (gnl_return != 0) //is_not_eof
// 	{
// 		tmp = *save;
// 		*save = ft_strjoin(*save, "\n");
// 		free(tmp);
// 	}
// 	free(line);
// 	return (line_len);
// }

// int			parse_line(char *line, t_all *all, int gnl_card)
// {
// 	int		i;
// 	int		line_length;
// 	int		result;

// 	line_length = ft_strlen(line);
// 	if (line_length == 0)
// 		return (0);
// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if (is_space(line[i]))
// 			i++;
// 		else if (is_type_identifier(line[i], line[i + 1], line))
// 			break ;
// 		else if (is_map_character(line[i], gnl_card)
// 			i += save_map(line, gnl_card);
// 		else
// 			return (-1);
// 	}
// 	return (1);
// }

int			check_header_name(char *header)
{
	int		i;

	if (!header || ft_strlen(header) > 4)
		return (-1);
	i = ft_strlen(header) - 1;
	if (header[i] == 'd' && header[i - 1] == 'u' && header[i - 2] == 'c' && header[i - 3] == '.')
		return (1);
    return 0;
}

// int			file_exists(char *file_name)
// {
// 	int		fd;
// 	int		len;

// 	len = ft_strlen(file_name);
// 	if (!file_name || len == 0)
// 		return (-1);
// 	fd = open(file_name, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		close(fd);
// 		return (-1);
// 	}
// 	if (!(file_name[len - 4] == '.' && file_name[len - 3] == 'x' && file_name[len - 2] == 'p' && file_name[len - 1] == 'm'))
// 		return (-1);
// 	return (1);
// }
