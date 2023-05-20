/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamePlay2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:09:39 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/20 17:03:59 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lose(void)
{
	ft_printf("set your heart ablaze\n");
	exit(1);
}

void	win(t_gamestate *game)
{
	void	*mlx;
	void	*mlx_win;
	int		img_width = 960;
	int		img_height = 540;
	ft_printf("nothing is stronger than family");
	mlx_destroy_image(game->wind.mlx, game->xax.coin);
	mlx_destroy_image(game->wind.mlx, game->xax.xot);
	mlx_destroy_image(game->wind.mlx, game->xax.enemy);
	mlx_destroy_image(game->wind.mlx, game->xax.ft_exit);
	mlx_destroy_image(game->wind.mlx, game->xax.madara);
	mlx_destroy_image(game->wind.mlx, game->xax.player);
	mlx_destroy_image(game->wind.mlx, game->xax.tuf);
	mlx_destroy_window(game->wind.mlx, game->wind.mlx_win);	
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 540, "Hello world!");
	game->xax.Dominik = mlx_xpm_file_to_image(mlx, "./Dom.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, game->xax.Dominik, 0, 0);
	mlx_loop(mlx);
}

void	move_two(int keystate, t_gamestate *game)
{
	if (keystate == 2 || keystate == 124)
	{
		if (game->map[game->player.y][game->player.x + 1] != '1'
			&& game->map[game->player.y][game->player.x + 1] != 'V' && game->map[game->player.y][game->player.x + 1] != 'M')
		{
			if (game->map[game->player.y][game->player.x + 1] != 'E' || game->number_coins == 0)
			{
				if (game->map[game->player.y][game->player.x + 1] == 'C')
					game->number_coins--;
				if (game->map[game->player.y][game->player.x + 1] == 'E')
					win(game);
				game->map[game->player.y][game->player.x + 1] = 'P';
				game->map[game->player.y][game->player.x] = '0';
				game->player.x++;
			}
		}
		else if (game->map[game->player.y][game->player.x + 1] == 'V' || game->map[game->player.y][game->player.x + 1] == 'M')
			lose();
	}
	else if (keystate == 1 || keystate == 125)
	{
		if (game->map[game->player.y + 1][game->player.x] != '1'
			&& game->map[game->player.y + 1][game->player.x] != 'V' && game->map[game->player.y + 1][game->player.x] != 'M')
		{
			if (game->map[game->player.y + 1][game->player.x] != 'E' || game->number_coins == 0)
			{
				if (game->map[game->player.y + 1][game->player.x] == 'C')
						game->number_coins--;	
				if (game->map[game->player.y + 1][game->player.x] == 'E')
					win(game);
				game->map[game->player.y + 1][game->player.x] = 'P';
				game->map[game->player.y][game->player.x] = '0';
				game->player.y++;
			}
		}
		else if (game->map[game->player.y + 1][game->player.x] == 'V' || game->map[game->player.y + 1][game->player.x] == 'M' )
			lose();
	}
}
