/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:17:24 by tchariss          #+#    #+#             */
/*   Updated: 2021/02/03 12:50:38 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	player_1
{
	float x, y; // позиция по х, у
	float a;    // направление
	float fov;  // поле зрение
}				player_2;



mlx = mlx_init();
    win = mlx_new_window(mlx, 1080, 720, "hello, vikos");
    gnl_card(var_gnl);
	while (var_gnl.s[var_gnl.y][var_gnl.x] == 1)
		mlx_pixel_put(mlx, win, 100, 100, 0xEDDBFF);
	
	}
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    mlx_loop(vars.mlx);