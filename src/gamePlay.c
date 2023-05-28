/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamePlay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:49:06 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/28 21:01:02 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_image_init(t_gamestate *game)
{
	game->xax.witdh = 50;
	game->xax.len = 50;
	game->xax.xot = mlx_xpm_file_to_image
		(game->wind.mlx, "./tuf1.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.tuf = mlx_xpm_file_to_image
		(game->wind.mlx, "./wall.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.ft_exit = mlx_xpm_file_to_image
		(game->wind.mlx, "./nezuko/nez3.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.enemy = mlx_xpm_file_to_image
		(game->wind.mlx, "./itachi/1.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.madara = mlx_xpm_file_to_image
		(game->wind.mlx, "./madara/0.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.madara1 = mlx_xpm_file_to_image
		(game->wind.mlx, "./madara/1.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.madara2 = mlx_xpm_file_to_image
		(game->wind.mlx, "./madara/2.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.madara3 = mlx_xpm_file_to_image
		(game->wind.mlx, "./madara/3.xpm", &game->xax.witdh, &game->xax.len);
	image_init_playe(game);
	image_init_coin(game);
}

void	fill_image(t_gamestate *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			mlx_put_image_to_window
				(game->wind.mlx, game->wind.mlx_win,
				game->xax.xot, i * 50, j * 50);
			if (game->map[j][i] == '1')
				mlx_put_image_to_window
				(game->wind.mlx, game->wind.mlx_win,
				game->xax.tuf, i * 50, j * 50);
			else
				fill_image_two(game, game->map[j][i], i, j);
			i++;
		}
		j++;
	}
}

int	move(int keystate, t_gamestate *game)
{
	game->keystate = keystate;
	if (keystate == 53)
	{
		destroy_image(game);
		system("leaks so_long");
		exit (0);
	}
	else
		move_two(keystate, game);
	fill_image(game);
	return (0);
}

void	mlx_hooks(t_gamestate *game)
{
	mlx_hook(game->wind.mlx_win, 2, 0, &move, game);
	mlx_hook(game->wind.mlx_win, 17, 0, &close_win, game);
	mlx_loop_hook(game->wind.mlx, &loop_for_mlx, game);
	mlx_loop(game->wind.mlx);
}

void	ft_open(t_gamestate *game)
{
	game->wind.mlx = mlx_init();
	game->wind.mlx_win = mlx_new_window
		(game->wind.mlx, (game->mapsize.x) * 50,
			(game->mapsize.y) * 50, "Hello world!");
	fill_image_init(game);
	fill_image(game);
	mlx_hooks(game);
}
