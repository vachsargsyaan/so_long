/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamePlay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:49:06 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/15 19:01:37 by vacsargs         ###   ########.fr       */
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
		mlx_put_image_to_window
			(game->wind.mlx, game->wind.mlx_win, game->xax.player,
			game->player.x * 50, game->player.y * 50);
	else if (c == 'V')
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win,
		game->xax.enemy, i * 50, j * 50);
	else if (c == 'C')
		mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win,
		game->xax.coin, i * 50, j * 50);
}

void	fill_image_init(t_gamestate *game)
{
	game->xax.witdh = 50;
	game->xax.len = 50;
	game->xax.xot = mlx_xpm_file_to_image
		(game->wind.mlx, "./tuf1.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.tuf = mlx_xpm_file_to_image
		(game->wind.mlx, "./wall.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.coin = mlx_xpm_file_to_image
		(game->wind.mlx, "./coin/1.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.ft_exit = mlx_xpm_file_to_image
		(game->wind.mlx, "./nezuko/nez3.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.player = mlx_xpm_file_to_image
		(game->wind.mlx, "./player/2.xpm", &game->xax.witdh, &game->xax.len);
	game->xax.enemy = mlx_xpm_file_to_image
		(game->wind.mlx, "./itachi/1.xpm", &game->xax.witdh, &game->xax.len);
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
// void	keypress(void *win)
// {
// 	(void)win;
// }
//  int	*draw(t_gamestate * game)
//  {
// 	(void) game;
// 	return (0);
//  }
// int	*draw(t_gamestate * game)
// {
// 	mlx_clear_window(game->mlx.ptr, game->mlx.win);//jnji patuhnay   
// 	mlx_put_image(&game);//nkari nory
// 	return(0);
// }

int	move(int keystate, t_gamestate *game)
{
	if (keystate == 13 || keystate == 126)
	{
		if (game->map[game->player.y - 1][game->player.x] != '1'
			&& game->map[game->player.y - 1][game->player.x] != 'V')
		{
			game->map[game->player.y - 1][game->player.x] = 'P';
			game->map[game->player.y][game->player.x] = '0';
			game->player.y--;
		}
		else if (game->map[game->player.y - 1][game->player.x] == 'V')
		{
			printf ("you lose\n");
			exit (1);
		}
	}
	else if (keystate == 0 || keystate == 123)
	{
		if (game->map[game->player.y][game->player.x - 1] != '1'
			&& game->map[game->player.y][game->player.x - 1] != 'V')
		{
			game->map[game->player.y][game->player.x - 1] = 'P';
			game->map[game->player.y][game->player.x] = '0';
			game->player.x--;
		}
		else if (game->map[game->player.y][game->player.x - 1] == 'V')
		{
			printf ("you lose\n");
			exit (1);
		}
	}
	else if (keystate == 2 || keystate == 124)
	{
		if (game->map[game->player.y][game->player.x + 1] != '1'
			&& game->map[game->player.y][game->player.x + 1] != 'V')
		{
			game->map[game->player.y][game->player.x + 1] = 'P';
			game->map[game->player.y][game->player.x] = '0';
			game->player.x++;
		}
		else if (game->map[game->player.y][game->player.x + 1] == 'V')
		{
			printf ("you lose\n");
			exit (1);
		}
	}
	else if (keystate == 1 || keystate == 125)
	{
		if (game->map[game->player.y + 1][game->player.x] != '1'
			&& game->map[game->player.y + 1][game->player.x] != 'V')
		{
			game->map[game->player.y + 1][game->player.x] = 'P';
			game->map[game->player.y][game->player.x] = '0';
			game->player.y++;
		}
		else if (game->map[game->player.y + 1][game->player.x] == 'V')
		{
			printf ("you lose\n");
			exit (1);
		}
	}
	fill_image(game);
	return (0);
}

int	close_win(t_gamestate *game)
{
	mlx_clear_window(game->wind.mlx, game->wind.mlx_win);
	mlx_destroy_window(game->wind.mlx, game->wind.mlx_win);
	return (0);
}

int	loop_for_mlx(t_gamestate *game)
{
	mlx_clear_window(game->wind.mlx, game->wind.mlx_win);
	return (0);
}

void	mlx_hooks(t_gamestate *game)
{
	mlx_hook(game->wind.mlx_win, 2, 0, move, game);
	// mlx_hook((*game)->wind.win, 17, 0, close_win, game);
	// mlx_loop_hook((*game)->wind.win, loop_for_mlx, game);
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
	// mlx_hook(game->wind.mlx_win, 2, 1l << 0, &keypress, &game);
	// mlx_loop_hook(game->wind.mlx_ptr, draw, &game);
}
