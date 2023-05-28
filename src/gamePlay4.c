/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamePlay4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:12:32 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/28 21:00:38 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freez(t_gamestate *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	i = 0;
	while (game->test_map[i])
	{
		free(game->test_map[i]);
		i++;
	}
	free(game->res);
}

void	move_three(int keystate, t_gamestate *game)
{
	if (keystate == 0 || keystate == 123)
	{
		if (game->map[game->player.y][game->player.x - 1] != '1'
			&& game->map[game->player.y][game->player.x - 1] != 'V'
				&& game->map[game->player.y][game->player.x - 1] != 'M')
		{
			if (game->map[game->player.y][game->player.x - 1] != 'E'
				|| game->number_coins == 0)
			{	
				if (game->map[game->player.y][game->player.x - 1] == 'C')
					game->number_coins--;
				if (game->map[game->player.y][game->player.x - 1] == 'E')
					win(game);
				game->map[game->player.y][game->player.x - 1] = 'P';
				game->map[game->player.y][game->player.x] = '0';
				game->player.x--;
				count(game);
			}
		}
		else if (game->map[game->player.y][game->player.x - 1] == 'V'
			|| game->map[game->player.y][game->player.x - 1] == 'M')
			lose(game);
	}
	else
		move_four(keystate, game);
}

void	move_four(int keystate, t_gamestate *game)
{
	if (keystate == 13 || keystate == 126)
	{
		if (game->map[game->player.y - 1][game->player.x] != '1'
			&& game->map[game->player.y - 1][game->player.x] != 'V'
				&& game->map[game->player.y - 1][game->player.x] != 'M')
		{
			if (game->map[game->player.y - 1][game->player.x] != 'E'
				|| game->number_coins == 0)
			{
				if (game->map[game->player.y - 1][game->player.x] == 'C')
					game->number_coins--;
				if (game->map[game->player.y - 1][game->player.x] == 'E')
					win(game);
				game->map[game->player.y - 1][game->player.x] = 'P';
				game->map[game->player.y][game->player.x] = '0';
				game->player.y--;
				count(game);
			}
		}
		else if (game->map[game->player.y - 1][game->player.x] == 'V'
			|| game->map[game->player.y - 1][game->player.x] == 'M')
			lose(game);
	}
	else
		move_five(keystate, game);
}

int	close_win(t_gamestate *game)
{
	mlx_clear_window(game->wind.mlx, game->wind.mlx_win);
	if (game->x == 1)
		destroy_image(game);
	if (game->x == 0)
		destroy_image1(game);
	if (game->x == 2)
		destroy_image2(game);
	system("leaks so_long");
	exit (0);
	return (0);
}

int	loop_for_mlx(t_gamestate *game)
{
	char	*str;

	if (game->newwin)
	{
		mlx_clear_window(game->wind.mlx, game->wind.mlx_win);
		str = ft_itoa(game->count);
		fill_image(game);
		mlx_string_put(game->wind.mlx, game->wind.mlx_win,
			1 * 24, 1 * 15, 0x000000, str);
		free(str);
	}
	return (0);
}
