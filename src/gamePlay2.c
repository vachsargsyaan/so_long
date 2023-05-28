/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamePlay2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:09:39 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/28 21:00:52 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lose(t_gamestate *game)
{
	int		img_width;
	int		img_height;

	game->newwin = 0;
	img_width = 500;
	img_height = 500;
	ft_printf("set your heart ablaze\n");
	destroy_image(game);
	ft_freez(game);
	game->wind.mlx = mlx_init();
	game->wind.mlx_win = mlx_new_window
		(game->wind.mlx, 500, 500, "Hello world!");
	game->xax.rengoku = mlx_xpm_file_to_image
		(game->wind.mlx, "./Rengoku.xpm", &img_width, &img_height);
	mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.rengoku, 0, 0);
	game->x = 0;
	mlx_hook(game->wind.mlx_win, 17, 0, &close_win, game);
	mlx_hook(game->wind.mlx_win, 2, 0, &esc, game);
	mlx_loop(game->wind.mlx);
	system("leaks so_long");
	exit(0);
}

void	win(t_gamestate *game)
{
	int		img_width;
	int		img_height;

	game->newwin = 0;
	img_width = 960;
	img_height = 540;
	ft_printf("nothing is stronger than family\n");
	destroy_image(game);
	ft_freez(game);
	game->x = 2;
	game->wind.mlx = mlx_init();
	game->wind.mlx_win = mlx_new_window
		(game->wind.mlx, 960, 540, "Hello world!");
	game->xax.dominik = mlx_xpm_file_to_image
		(game->wind.mlx, "./Dom.xpm", &img_width, &img_height);
	mlx_put_image_to_window
		(game->wind.mlx, game->wind.mlx_win, game->xax.dominik, 0, 0);
	mlx_hook(game->wind.mlx_win, 17, 0, &close_win, game);
	mlx_hook(game->wind.mlx_win, 2, 0, &esc, game);
	mlx_loop(game->wind.mlx);
	system("leaks so_long");
	exit(0);
}

void	move_two(int keystate, t_gamestate *game)
{
	if (keystate == 2 || keystate == 124)
	{
		if (game->map[game->player.y][game->player.x + 1] != '1'
			&& game->map[game->player.y][game->player.x + 1] != 'V'
				&& game->map[game->player.y][game->player.x + 1] != 'M')
		{
			if (game->map[game->player.y][game->player.x + 1] != 'E'
				|| game->number_coins == 0)
			{
				if (game->map[game->player.y][game->player.x + 1] == 'C')
					game->number_coins--;
				if (game->map[game->player.y][game->player.x + 1] == 'E')
					win(game);
				game->map[game->player.y][game->player.x + 1] = 'P';
				game->map[game->player.y][game->player.x] = '0';
				game->player.x++;
				count(game);
			}
		}
		else if (game->map[game->player.y][game->player.x + 1] == 'V'
			|| game->map[game->player.y][game->player.x + 1] == 'M')
			lose(game);
	}
	else
		move_three(keystate, game);
}

void	move_five(int keystate, t_gamestate *game)
{
	if (keystate == 1 || keystate == 125)
	{
		if (game->map[game->player.y + 1][game->player.x] != '1'
			&& game->map[game->player.y + 1][game->player.x] != 'V'
				&& game->map[game->player.y + 1][game->player.x] != 'M')
		{
			if (game->map[game->player.y + 1][game->player.x] != 'E'
			|| game->number_coins == 0)
			{
				if (game->map[game->player.y + 1][game->player.x] == 'C')
					game->number_coins--;
				if (game->map[game->player.y + 1][game->player.x] == 'E')
					win(game);
				game->map[game->player.y + 1][game->player.x] = 'P';
				game->map[game->player.y][game->player.x] = '0';
				game->player.y++;
				count(game);
			}
		}
		else if (game->map[game->player.y + 1][game->player.x] == 'V'
			|| game->map[game->player.y + 1][game->player.x] == 'M' )
			lose(game);
	}
}
