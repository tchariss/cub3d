/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:32:09 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/05 20:20:05 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int			free_gnl(t_gnl **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (-1);
}

int			proverka_static_memory(char *static_memory, char **line)
{
	char		*next_line;

	next_line = NULL;
	if (static_memory != NULL)
	{
		if ((next_line = ft_strchr(static_memory, '\n')))
		{
			*next_line = '\0';
			if (!(*line = ft_strdup(static_memory)))
				return (-1);
			ft_strcopy(static_memory, ++next_line);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup(static_memory)))
				return (-1);
		}
	}
	else
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	return (0);
}

int			get_line(t_gnl *gnl, char ***line, char **static_memory,
int count_sym_in_str)
{
	char	*saveper;

	gnl->buf[count_sym_in_str] = '\0';
	if ((gnl->ukaz_n = ft_strchr(gnl->buf, '\n')) != NULL)
	{
		*gnl->ukaz_n = '\0';
		if (!(*static_memory = ft_strdup(++gnl->ukaz_n)))
			return (-1);
	}
	saveper = **line;
	if (!(**line = ft_strjoin(**line, gnl->buf)))
		return (-1);
	free(saveper);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	t_gnl		*gnl;
	int			count_sym_in_str;
	int			check;
	static char	*static_memory = NULL;

	check = 0;
	count_sym_in_str = 0;
	if (line == NULL || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0
	|| BUFFER_SIZE >= 8000000)
		return (-1);
	if (!(gnl = (t_gnl *)malloc(sizeof(t_gnl))))
		return (-1);
	gnl->ukaz_n = NULL;
	if ((check = proverka_static_memory(static_memory, line)) == -1)
		return (free_gnl(&gnl));
	if (check != 1)
		free_str(&static_memory);
	while (check == 0 && gnl->ukaz_n == 0 &&
	(count_sym_in_str = read(fd, gnl->buf, BUFFER_SIZE)) > 0)
		if (get_line(gnl, &line, &static_memory, count_sym_in_str) == -1)
			return (free_gnl(&gnl));
	free(gnl);
	return ((count_sym_in_str || check) ? 1 : 0);
}
