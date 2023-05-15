/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structurFunction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:11:08 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/15 18:59:34 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_coord(t_gamestate *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] && game->map[j][i] != 'P')
			i++;
		if (game->map[j][i] == 'P')
			break ;
		j++;
	}
	game->player.x = i;
	game->player.y = j;
	number_of_coins(game);
}

void	map_len(t_gamestate *game)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(game->map[0]);
	while (game->map[j] != NULL)
		j++;
	game->mapsize.x = i;
	game->mapsize.y = j;
}

void	number_of_coins(t_gamestate *game)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	game->number_coins = c;
}