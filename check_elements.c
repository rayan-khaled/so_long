/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:33:37 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/02 20:10:20 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char ch, int *p, int *e, int *c)
{
	if (ch == 'P')
		(*p)++;
	else if (ch == 'E')
		(*e)++;
	else if (ch == 'C')
		(*c)++;
	else if (ch != '0' && ch != '1')
		return (1);
	return (0);
}

void	update_player_pos(t_game *g, int x, int y)
{
	g->px = x;
	g->py = y;
}

int	check_elements(char **map, t_game *g)
{
	int	p;
	int	e;
	int	c;
	int	y;
	int	x;

	p = 0;
	e = 0;
	c = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (check_char(map[y][x], &p, &e, &c))
				return (1);
			if (map[y][x] == 'P')
				update_player_pos(g, x, y);
		}
	}
	if (p != 1 || e != 1 || c < 1)
		return (1);
	g->collectibles = c;
	return (0);
}
