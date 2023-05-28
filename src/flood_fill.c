/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:53:28 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/28 19:16:28 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_coord size, t_coord cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != to_fill && tab[cur.y][cur.x] != 'C'
		&& tab[cur.y][cur.x] != 'E' && tab[cur.y][cur.x] != '0'))
		return ;
	tab[cur.y][cur.x] = '-';
	fill(tab, size, (t_coord){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_coord){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_coord){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_coord){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_coord size, t_coord begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
