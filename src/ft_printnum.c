/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:04:33 by vacsargs          #+#    #+#             */
/*   Updated: 2023/04/25 18:12:55 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printnum(int num)
{
	long	nb;
	int		i;

	nb = num;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb > 9)
	{
		i += ft_printnum(nb / 10);
		i += ft_printnum(nb % 10);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
		i++;
	}
	return (i);
}
