/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamePlay6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:06:25 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/30 17:52:50 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right1(t_gamestate *game, int *i)
{
	if ((*i) <= 40 && (game->keystate == 2 || game->keystate == 124))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.right2,
		game->player.x * 50, game->player.y * 50);
		(*i)++;
	}
	else if ((*i) < 51 && (game->keystate == 2 || game->keystate == 124))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.right3,
		game->player.x * 50, game->player.y * 50);
		(*i) = 0;
	}
}

void	coin_anim2(t_gamestate *game, int i, int j, int *z)
{
	if ((*z) <= 75 && (*z) > 65)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin6, i * 50, j * 50);
		(*z)++;
	}
	else if ((*z) <= 85 && (*z) > 75)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin7, i * 50, j * 50);
		(*z)++;
	}
	else if ((*z) <= 95 && (*z) > 85)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin8, i * 50, j * 50);
		(*z)++;
	}
	else
		coin_anim3(game, i, j, z);
}

void	coin_anim3(t_gamestate *game, int i, int j, int *z)
{
	if ((*z) <= 105 && (*z) > 95)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin9, i * 50, j * 50);
		(*z)++;
	}
	else if ((*z) < 115 && (*z) > 105)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin10, i * 50, j * 50);
		(*z)++;
	}
	else if ((*z) == 115)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin3, i * 50, j * 50);
		(*z) = 0;
	}
}

void	count(t_gamestate *game)
{
	game->count++;
}
