/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:44:38 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/04 17:01:48 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define KEY_ESC 65307
# define EVENT_KEY_PRESS 2
# define EVENT_DESTROY 17

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		moves;
	int		collectibles;
	int		px;
	int		py;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_col;
}			t_game;

char		*get_next_line(int fd);
size_t		ft_strlen_gnl(const char *s);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_strdup_gnl(const char *s);
char		*ft_substr_gnl(char *s, size_t start, size_t len);
char		*ft_strappend_gnl(char *s1, char *s2);
char		*extract_line(char *stash);
char		*trim_stash(char *stash);
int			ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		**dup_map(char **map);
void		ft_putnbr_fd(int n, int fd);
int			ft_strcmp(const char *s1, const char *s2);
int			handle_close(t_game *g);
char		**add_line(char **old, char *line, int count);
char		**read_file(const char *path);
char		**read_fd(int fd);
void		consume_remaining_lines(int fd);
int			is_invalid_line(char *line);
void		trim_newline(char *line);
void		free_map(char **map);
void		free_images(t_game *g);
int			check_rectangular(char **map);
int			check_top_bottom(char *row);
int			check_walls(char **map);
int			check_char(char ch, int *p, int *e, int *c);
void		update_player_pos(t_game *g, int x, int y);
int			check_elements(char **map, t_game *g);
void		flood(char **map, int x, int y);
void		find_player(char **map, int *px, int *py);
int			all_reached(char **map);
int			check_path(char **map);
void		validate_map(char **map, t_game *g);
int			get_map_width(char **map);
int			get_map_height(char **map);
void		draw_map(t_game *g);
int			init_mlx(t_game *g);
void		draw_tile(t_game *g, char tile, int x, int y);
void		draw_map(t_game *g);
int			handle_key(int key, t_game *g);
int			is_wall(t_game *g, int x, int y);
int			handle_collectible(t_game *g, int x, int y);
int			handle_exit(t_game *g, int x, int y);
void		move_player(t_game *g, int dx, int dy);
int			check_extensions(char *file, char *ext);

#endif