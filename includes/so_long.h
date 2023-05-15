/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:00:09 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/15 18:41:47 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_pers
{
	int		len;
	int		witdh;
	void	*player;
	void	*coin;
	void	*ft_exit;
	void	*enemy;
	void	*xot;
	void	*tuf;
}t_pers;

typedef struct s_open
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_ptr;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}t_open;

typedef struct s_coord
{
	int	x;
	int	y;
}t_coord;

typedef struct s_gamestate
{
	t_coord	player;
	t_coord	mapsize;
	char	**map;
	char	**test_map;
	char	*res;
	char	*line;
	t_open	wind;
	t_pers	xax;
	int		number_coins;
}t_gamestate;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_printf(const char *str, ...);
int		ft_cahrs(const char *str);
int		ft_for(va_list args, const char format);
int		ft_printnum(int num);
int		ft_print_hex(unsigned long long nb, const char format);
int		ft_print_point(unsigned long long lu);
int		ft_it(unsigned int num);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	search_player(char **map);
void	ft_coord(t_gamestate *game);
void	map_len(t_gamestate *game);
void	ft_error(void);
void	borders_chek(char	**map);
void	search_exit(char **map);
void	flood_fill(char **tab, t_coord size, t_coord begin);
void	fill(char **tab, t_coord size, t_coord cur, char to_fill);
void	player_can_win(char **map);
void	ft_open(t_gamestate *game);
void	ft_call(t_gamestate	*game);
void	ft_eva(char **s);
void	fill_image(t_gamestate *game);
void	fill_image_init(t_gamestate *game);
void	number_of_coins(t_gamestate *game);
int		*draw(t_gamestate *game);

#endif