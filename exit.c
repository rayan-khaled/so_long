/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:20:00 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/02 20:11:27 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	free_images(g);
	if (g->map)
		free_map(g->map);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit(0);
}
