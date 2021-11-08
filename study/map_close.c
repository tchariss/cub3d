/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:59:06 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/05 16:59:31 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	press_key(int keycode, void *mlx, void *win)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void     close_my(int keycode, void *mlx, void *win)
{
    mlx_destroy_window(mlx, win);
}

mlx_hook(win, 2, 0, &press_key, &map);