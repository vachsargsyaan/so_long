/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamePlay5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:02:48 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/28 18:40:29 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_image_two(t_gamestate *game, char c, int i, int j)
{
	if (c == 'E')
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
			game->xax.ft_exit, i * 50, j * 50);
	else if (c == 'P')
		ft_player(game);
	else if (c == 'V')
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win,
		game->xax.enemy, i * 50, j * 50);
	else if (c == 'C')
		coin_anim(game, i, j);
	else if (c == 'M')
		ft_madara(game, i, j);
}

void	ft_right(t_gamestate *game)
{
	static int	i = 0;

	if (i <= 20 && (game->keystate == 2 || game->keystate == 124))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.right,
		game->player.x * 50, game->player.y * 50);
		i++;
	}
	else if (i <= 30 && (game->keystate == 2 || game->keystate == 124))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.right1,
		game->player.x * 50, game->player.y * 50);
		i++;
	}
	else
		ft_right1(game, &i);
}

void	ft_madara1(t_gamestate *game, int i, int j, int *z)
{
	if ((*z) <= 15 * game->madara_count && (*z) > 10 * game->madara_count)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.madara2, i * 50, j * 50);
		(*z)++;
	}
	else if ((*z) < 20 * game->madara_count && (*z) > 15 * game->madara_count)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.madara3, i * 50, j * 50);
		(*z)++;
	}
	else if ((*z) == 20 * game->madara_count)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.madara3, i * 50, j * 50);
		(*z) = 0;
	}
}

void	coin_anim1(t_gamestate *game, int i, int j, int *z)
{
	if ((*z) <= 45 && (*z) > 35)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin3, i * 50, j * 50);
		(*z)++;
	}
	else if ((*z) <= 55 && (*z) > 45)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin4, i * 50, j * 50);
		(*z)++;
	}
	else if ((*z) <= 65 && (*z) > 55)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin5, i * 50, j * 50);
		(*z)++;
	}
	else
		coin_anim2(game, i, j, z);
}

void	ft_player1(t_gamestate *game, int *i)
{
	if ((*i) <= 40 && (game->keystate == 0 || game->keystate == 123))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.player3,
		game->player.x * 50, game->player.y * 50);
		(*i)++;
	}
	else if ((*i) < 51 && (game->keystate == 0 || game->keystate == 123))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.player4,
		game->player.x * 50, game->player.y * 50);
		(*i) = 0;
	}
	else
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.player,
		game->player.x * 50, game->player.y * 50);
}
