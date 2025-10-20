/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:06:48 by rakhaled          #+#    #+#             */
/*   Updated: 2025/09/29 14:19:22 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr_gnl(stash, 0, i);
	return (line);
}

char	*trim_stash(char *stash)
{
	int		i;
	int		j;
	char	*leftovers;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	leftovers = malloc(ft_strlen_gnl(stash + i) + 1);
	if (!leftovers)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		leftovers[j++] = stash[i++];
	leftovers[j] = '\0';
	free(stash);
	return (leftovers);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr_gnl(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		stash = ft_strappend_gnl(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	if (bytes == -1)
		return (free(buf), free(stash), NULL);
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = trim_stash(stash);
	return (line);
}
