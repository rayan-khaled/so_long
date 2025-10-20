/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:41:38 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/02 20:04:33 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return ;
	}
	map[y][x] = 'V';
	flood(map, x + 1, y);
	flood(map, x - 1, y);
	flood(map, x, y + 1);
	flood(map, x, y - 1);
}

void	find_player(char **map, int *px, int *py)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*py = y;
				*px = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	all_reached(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_path(char **map)
{
	char	**copy;
	int		px;
	int		py;

	copy = dup_map(map);
	if (!copy)
	{
		return (1);
	}
	find_player(copy, &px, &py);
	flood(copy, px, py);
	if (!all_reached(copy))
	{
		free_map(copy);
		return (1);
	}
	free_map(copy);
	return (0);
}
