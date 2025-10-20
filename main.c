/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:10:00 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/04 16:54:49 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!check_extensions(argv[1], ".ber"))
	{
		write(1, "Error not .ber\n", 15);
		return (1);
	}
	g.map = read_file(argv[1]);
	if (!g.map)
		return (1);
	validate_map(g.map, &g);
	g.moves = 0;
	if (!init_mlx(&g))
		return (free_map(g.map), 1);
	draw_map(&g);
	mlx_key_hook(g.win, handle_key, &g);
	mlx_hook(g.win, EVENT_DESTROY, 0, handle_close, &g);
	mlx_loop(g.mlx);
	return (0);
}
