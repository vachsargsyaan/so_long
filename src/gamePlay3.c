/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamePlay3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:22:01 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/23 17:41:42 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_madara(t_gamestate *game, int i, int j)
{
	static int	z = 0;

	if (z <= 5)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.madara, i * 50, j * 50);
		z++;
	}
	else if (z <= 10 && z > 5)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.madara1, i * 50, j * 50);
		z++;
	}
	else if (z <= 15 && z > 10)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.madara2, i * 50, j * 50);
		z++;
	}
	else if (z < 20 && z > 15)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.madara3, i * 50, j * 50);
		z++;
	}
	else if (z == 20)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.madara3, i * 50, j * 50);
		z = 0;
	}
}

void	coin_anim(t_gamestate *game, int i, int j)
{
	static int	z = 0;

	if (z <= 15)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin, i * 50, j * 50);
			z++;
	}
	else if (z <= 25 && z > 15)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin1, i * 50, j * 50);
		z++;
	}
	else if (z <= 35 && z > 25)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin2, i * 50, j * 50);
		z++;
	}
	else if (z <= 45 && z > 35)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin3, i * 50, j * 50);
		z++;
	}
	else if (z <= 55 && z > 45)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin4, i * 50, j * 50);
		z++;
	}
	else if (z <= 65 && z > 55)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin5, i * 50, j * 50);
		z++;
	}
	else if (z <= 75 && z > 65)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin6, i * 50, j * 50);
		z++;
	}
	else if (z <= 85 && z > 75)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin7, i * 50, j * 50);
		z++;
	}
	else if (z <= 95 && z > 85)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin8, i * 50, j * 50);
		z++;
	}
	else if (z <= 105 && z > 95)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin9, i * 50, j * 50);
		z++;
	}
	else if (z < 115 && z > 105)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin10, i * 50, j * 50);
		z++;
	}
	else if (z == 115)
	{
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win,
				game->xax.coin3, i * 50, j * 50);
		z = 0;
	}
}

void	image_init_coin(t_gamestate *game)
{
	game->xax.coin = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/0.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin1 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/1.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin2 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/2.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin3 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/3.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin4 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/4.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin5 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/5.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin6 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/6.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin7 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/7.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin8 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/8.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin9 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/9.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin10 = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/10.xpm", &game->xax.witdh, &game->xax.len);
}

void	image_init_playe(t_gamestate *game)
{
	game->xax.player = mlx_xpm_file_to_image
		(game->wind.mlx, "./player/0.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.player1 = mlx_xpm_file_to_image
		(game->wind.mlx, "./player/1.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.player2 = mlx_xpm_file_to_image
		(game->wind.mlx, "./player/2.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.player3 = mlx_xpm_file_to_image
		(game->wind.mlx, "./player/3.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.player4 = mlx_xpm_file_to_image
		(game->wind.mlx, "./player/4.xpm", &game->xax.witdh, &game->xax.len);
}

void	ft_player(t_gamestate *game)
{
	static int	i = -1;

	if (i <= 20 && (game->keystate == 0 || game->keystate == 123))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.player1,
		game->player.x * 50, game->player.y * 50);
		i++;
	}
	else if (i <= 20 && (game->keystate == 0 || game->keystate == 123))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.player2,
		game->player.x * 50, game->player.y * 50);
		i++;
	}
	else if (i <= 30 && (game->keystate == 0 || game->keystate == 123))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.player3,
		game->player.x * 50, game->player.y * 50);
		i++;
	}
	else if (i < 41 && (game->keystate == 0 || game->keystate == 123))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.player4,
		game->player.x * 50, game->player.y * 50);
		i = 0;
	}
	else if (i < 41 && (game->keystate == 0 || game->keystate == 123))
	{
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.player4,
		game->player.x * 50, game->player.y * 50);
		i = 0;
	}
	else
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.player,
		game->player.x * 50, game->player.y * 50);
}