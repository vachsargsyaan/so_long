/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchError.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:16:02 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/23 18:11:36 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return ;
			j++;
		}
		i++;
	}
	ft_printf("Error");
	system("leaks so_long");
	exit (0);
}

void	borders_chek(char	**map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][0] != '1')
				ft_error();
			j++;
		}
		if (map[i][j - 1] != '1')
			ft_error();
		i++;
	}
}

void	search_exit(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				c++;
			j++;
		}
		i++;
	}
	if (c != 1)
		ft_error();
}

void	player_can_win(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P' || map[j][i] == 'E' || map[j][i] == 'C')
				ft_error();
			i++;
		}
		j++;
	}
}

void	ft_call(t_gamestate	*game)
{
	int	z;
	int	i;

	i = 0;
	game->test_map = ft_split(game->res, '\n');
	z = -1;
	while (game->map[++z + 1] != NULL)
		if (ft_strlen(game->map[z]) != ft_strlen(game->map[z + 1]))
			ft_error();
	z = 0;
	while (game->map[z][i])
	{
		if (game->map[z][i] != '1')
			ft_error();
		i++;
	}
	ft_eva(game->map);
	search_player(game->map);
	borders_chek(game->map);
	search_exit(game->map);
	ft_coord(game);
	map_len(game);
	flood_fill(game->test_map, game->mapsize, game->player);
	player_can_win(game->test_map);
	ft_open(game);
}
