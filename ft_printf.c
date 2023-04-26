/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:38:05 by vacsargs          #+#    #+#             */
/*   Updated: 2023/04/25 18:12:56 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_for(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_print_char(va_arg(args, int));
	else if (format == 's')
		i += ft_cahrs(va_arg(args, char *));
	else if (format == 'p')
		i += ft_print_point(va_arg(args, unsigned long long));
	else if (format == 'i' || format == 'd')
		i += ft_printnum(va_arg(args, int));
	else if (format == 'u')
		i += ft_it(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		i += ft_print_char('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_for(args, str[++i]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
