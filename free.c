/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:35:16 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/01 13:36:24 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_game *g)
{
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_col)
		mlx_destroy_image(g->mlx, g->img_col);
}
