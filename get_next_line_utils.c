/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:06:54 by rakhaled          #+#    #+#             */
/*   Updated: 2025/09/29 14:20:21 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(ft_strlen_gnl(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr_gnl(char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen_gnl(s);
	if (!s || start >= s_len)
		return (ft_strdup_gnl(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strappend_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!s2)
		return (s1);
	res = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!res)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	free(s1);
	return (res);
}
