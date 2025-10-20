/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:03:19 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/01 13:39:00 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width])
		width++;
	return (width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	*load_img(void *mlx, char *path)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!img)
	{
		write(2, "Error: cannot load ", 20);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
	}
	return (img);
}

int	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	g->width = get_map_width(g->map) * 32;
	g->height = get_map_height(g->map) * 32;
	g->win = mlx_new_window(g->mlx, g->width, g->height, "so_long");
	if (!g->win)
		return (0);
	g->img_floor = load_img(g->mlx, "assets/floor.xpm");
	g->img_wall = load_img(g->mlx, "assets/wall.xpm");
	g->img_col = load_img(g->mlx, "assets/col.xpm");
	g->img_exit = load_img(g->mlx, "assets/exit.xpm");
	g->img_player = load_img(g->mlx, "assets/player.xpm");
	if (!g->img_floor || !g->img_wall || !g->img_col || !g->img_exit
		|| !g->img_player)
		return (0);
	return (1);
}
