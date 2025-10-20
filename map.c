/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:50:29 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/04 16:26:14 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**add_line(char **old, char *line, int count)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (count + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = ft_strdup(old[i]);
		if (!new[i])
			return (free_map(new), NULL);
		i++;
	}
	new[count] = ft_strdup(line);
	free(line);
	free_map(old);
	if (!new[count])
		return (free_map(new), NULL);
	new[count + 1] = NULL;
	return (new);
}

char	**read_file(const char *path)
{
	int		fd;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = read_fd(fd);
	close(fd);
	return (map);
}
