/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:22:04 by rakhaled          #+#    #+#             */
/*   Updated: 2025/09/30 12:18:25 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(char **map)
{
	int	i;
	int	len;
	int	curr;

	if (!map || !map[0])
		return (1);
	len = 0;
	while (map[0][len])
		len++;
	i = 1;
	while (map[i])
	{
		curr = 0;
		while (map[i][curr])
			curr++;
		if (curr != len)
			return (1);
		i++;
	}
	return (0);
}

int	check_top_bottom(char *row)
{
	int	i;

	i = 0;
	if (!row)
		return (1);
	while (row[i])
	{
		if (row[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	y;
	int	width;

	width = 0;
	if (!map || !map[0])
		return (0);
	while (map[0][width])
		width++;
	if (check_top_bottom(map[0]))
		return (1);
	y = 1;
	while (map[y + 1])
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (1);
		y++;
	}
	if (check_top_bottom(map[y]))
		return (1);
	return (0);
}
