/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:04:03 by tchariss          #+#    #+#             */
/*   Updated: 2021/03/05 17:09:46 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// int        create_trgb(int r, int g, int b)
// {
//     return (r << 16 | g << 8 | b);
// }
 
// int        get_t(int trgb)
// {
//     return (trgb & (0xFF << 24));
// }
int        get_r(int trgb)
{
    return (trgb & (0xFF << 16));
}
int        get_g(int trgb)
{
    return (trgb & (0xFF << 8));
}
int        get_b(int trgb)
{
    return (trgb & 0xFF);
}

int main ()
{
    printf("rgb color - %i \n", get_r(6));
    printf("rgb color - %i \n", get_g(4));
    printf("rgb color - %i \n", get_b(6));
}