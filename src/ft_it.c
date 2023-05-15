/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_it.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:43:51 by vacsargs          #+#    #+#             */
/*   Updated: 2023/04/25 17:59:31 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_it(unsigned int num)
{
	long				nb;
	unsigned int		i;

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
		i += ft_it(nb / 10);
		i += ft_it(nb % 10);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
		i++;
	}
	return (i);
}
