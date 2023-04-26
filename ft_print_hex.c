/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:52:13 by vacsargs          #+#    #+#             */
/*   Updated: 2023/04/25 17:59:23 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_hex_len(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static void	ft_hex(unsigned long long nb, const char format)
{
	unsigned long long	i;
	char				b;
	char				a;

	if (nb < 16)
	{
		i = nb;
		nb = 0;
	}
	else
	{
		i = nb % 16;
		nb /= 16;
	}
	if (nb > 0)
		ft_hex(nb, format);
	b = "0123456789ABCDEF"[i];
	a = "0123456789abcdef"[i];
	if (format == 'X')
		write(1, &b, 1);
	if (format == 'x')
		write(1, &a, 1);
}

int	ft_print_hex(unsigned long long nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	ft_hex(nb, format);
	return (ft_hex_len(nb));
}
