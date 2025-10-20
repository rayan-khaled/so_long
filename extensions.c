/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:46:23 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/02 19:01:41 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extensions(char *file, char *ext)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(ext);
	if (len_file < len_ext)
		return (0);
	return (!ft_strcmp(file + len_file - len_ext, ext));
}
