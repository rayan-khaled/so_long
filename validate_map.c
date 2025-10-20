/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:58:58 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/02 20:12:57 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(char **map, t_game *g)
{
	if (check_rectangular(map))
	{
		write(2, "Error\n", 6);
		free_map(map);
		exit(1);
	}
	if (check_walls(map))
	{
		write(2, "Error\n", 6);
		free_map(map);
		exit(1);
	}
	if (check_elements(map, g))
	{
		write(2, "Error\n", 6);
		free_map(map);
		exit(1);
	}
	if (check_path(map))
	{
		write(2, "Error\n", 6);
		free_map(map);
		exit(1);
	}
}
