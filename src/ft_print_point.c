/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:56:12 by vacsargs          #+#    #+#             */
/*   Updated: 2023/04/25 17:59:16 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_point(unsigned long long lu)
{
	int					count;

	count = 0;
	if (!lu)
		return (ft_cahrs("0x0"));
	count += ft_cahrs("0x");
	count += ft_print_hex(lu, 'x');
	return (count);
}
