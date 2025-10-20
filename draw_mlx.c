/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:30:00 by rakhaled          #+#    #+#             */
/*   Updated: 2025/09/30 16:02:20 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *g, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_wall, x * 32, y * 32);
	else if (tile == '0')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_floor, x * 32, y * 32);
	else if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_col, x * 32, y * 32);
	else if (tile == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit, x * 32, y * 32);
	else if (tile == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_player, x * 32, y * 32);
}

void	draw_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			draw_tile(g, g->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
