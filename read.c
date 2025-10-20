/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:25:29 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/04 16:26:25 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	consume_remaining_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	is_invalid_line(char *line)
{
	return (line[0] == '\n' || line[0] == '\0');
}

void	trim_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

char	**read_fd(int fd)
{
	int		count;
	char	*line;
	char	**map;

	map = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_invalid_line(line))
		{
			free(line);
			consume_remaining_lines(fd);
			return (map);
		}
		trim_newline(line);
		map = add_line(map, line, count++);
		if (!map)
			return (consume_remaining_lines(fd), NULL);
		line = get_next_line(fd);
	}
	if (count == 0)
		return (NULL);
	return (map);
}
