/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 06:39:38 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/14 06:44:24 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

micro

typedef struct s_all;
{
    int w;
    int h;
    char back;
    char *zone;
    char type;
    float x;
    float y;
    float width;
    float height;
    char color;
}               t_all;

int check(t_all *all)
{
    int i;
    int j;

    if (all->width <= 0.00000000 || all->height <= 0.00000000) || (all->type != 'R' && all->type != 'r'))
        return 1;
    if i = -1;
    while (++i < all->w)
    {
        
    }
}