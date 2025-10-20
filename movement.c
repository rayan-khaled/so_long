/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:49:53 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/02 19:00:15 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int key, t_game *g)
{
	if (key == KEY_ESC)
		handle_close(g);
	else if (key == KEY_W)
		move_player(g, 0, -1);
	else if (key == KEY_A)
		move_player(g, -1, 0);
	else if (key == KEY_S)
		move_player(g, 0, 1);
	else if (key == KEY_D)
		move_player(g, 1, 0);
	return (0);
}

int	is_wall(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		return (1);
	return (0);
}

int	handle_collectible(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'C')
	{
		g->collectibles--;
		g->map[y][x] = '0';
		return (1);
	}
	return (0);
}

int	handle_exit(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'E')
	{
		if (g->collectibles == 0)
		{
			handle_close(g);
		}
		return (1);
	}
	return (0);
}

void	move_player(t_game *g, int dx, int dy)
{
	int	new_x;
	int	new_y;
	int	px;
	int	py;

	find_player(g->map, &px, &py);
	new_x = px + dx;
	new_y = py + dy;
	if (is_wall(g, new_x, new_y) || handle_exit(g, new_x, new_y))
		return ;
	handle_collectible(g, new_x, new_y);
	g->map[py][px] = '0';
	g->map[new_y][new_x] = 'P';
	g->moves++;
	write(1, "Moves: ", 8);
	ft_putnbr_fd(g->moves, 1);
	write(1, "\n", 1);
	draw_map(g);
}
