/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:24:39 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:42 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image_player(t_gamestate *game)
{
	mlx_destroy_image(game->wind.mlx, game->xax.player);
	mlx_destroy_image(game->wind.mlx, game->xax.player1);
	mlx_destroy_image(game->wind.mlx, game->xax.player2);
	mlx_destroy_image(game->wind.mlx, game->xax.player3);
	mlx_destroy_image(game->wind.mlx, game->xax.player4);
	mlx_destroy_image(game->wind.mlx, game->xax.right);
	mlx_destroy_image(game->wind.mlx, game->xax.right1);
	mlx_destroy_image(game->wind.mlx, game->xax.right2);
	mlx_destroy_image(game->wind.mlx, game->xax.right3);
}

void	destroy_image(t_gamestate *game)
{
	mlx_destroy_image(game->wind.mlx, game->xax.coin);
	mlx_destroy_image(game->wind.mlx, game->xax.coin1);
	mlx_destroy_image(game->wind.mlx, game->xax.coin2);
	mlx_destroy_image(game->wind.mlx, game->xax.coin3);
	mlx_destroy_image(game->wind.mlx, game->xax.coin4);
	mlx_destroy_image(game->wind.mlx, game->xax.coin5);
	mlx_destroy_image(game->wind.mlx, game->xax.coin6);
	mlx_destroy_image(game->wind.mlx, game->xax.coin7);
	mlx_destroy_image(game->wind.mlx, game->xax.coin8);
	mlx_destroy_image(game->wind.mlx, game->xax.coin9);
	mlx_destroy_image(game->wind.mlx, game->xax.coin10);
	mlx_destroy_image(game->wind.mlx, game->xax.xot);
	mlx_destroy_image(game->wind.mlx, game->xax.enemy);
	mlx_destroy_image(game->wind.mlx, game->xax.ft_exit);
	mlx_destroy_image(game->wind.mlx, game->xax.madara);
	mlx_destroy_image(game->wind.mlx, game->xax.madara1);
	mlx_destroy_image(game->wind.mlx, game->xax.madara2);
	mlx_destroy_image(game->wind.mlx, game->xax.madara3);
	mlx_destroy_image(game->wind.mlx, game->xax.tuf);
	destroy_image_player(game);
	mlx_destroy_window(game->wind.mlx, game->wind.mlx_win);
}

void	destroy_image1(t_gamestate *game)
{
	mlx_destroy_image(game->wind.mlx, game->xax.rengoku);
}

void	destroy_image2(t_gamestate *game)
{
	mlx_destroy_image(game->wind.mlx, game->xax.dominik);
}

int	esc(int keystate, t_gamestate *game)
{
	if (keystate == 53)
		close_win(game);
	return (0);
}
