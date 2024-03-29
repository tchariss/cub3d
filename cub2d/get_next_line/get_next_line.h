/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:14:26 by tchariss          #+#    #+#             */
/*   Updated: 2021/03/27 14:03:52 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_gnl
{
	char		buf[BUFFER_SIZE + 1];
	char		*ukaz_n;
}				t_gnl;

int				get_next_line(int fd, char **line);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcopy(char *s1, const char *s2);

#endif
