/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:14:45 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/29 16:29:38 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void *
mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

int
mlx_clear_window(void *mlx_ptr, void *win_ptr);

int
mlx_destroy_window(void *mlx_ptr, void *win_ptr);

void *
mlx_init();