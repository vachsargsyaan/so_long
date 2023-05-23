/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:00:00 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/23 20:43:01 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	real_len;

	if (!s)
		return (NULL);
	real_len = ft_strlen(s);
	if ((size_t)start > real_len)
		return (ft_strdup(""));
	if (len > real_len)
		len = real_len;
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = *(s + start + i);
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*c;

	d = (char *)dst;
	c = (char *)src;
	if (!dst && !src)
		return (0);
	if ((dst == src) || n == 0)
		return (dst);
	while (n--)
	d[n] = c[n];
	return (d);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1)+1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	ft_memcpy(str, s1, len);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char const	*p;

	p = s1;
	if (!p || !set)
		return (0);
	while (*p && ft_strchr(set, *p))
		++p;
	if (*p == '\0')
		return (ft_strdup(""));
	i = ft_strlen(p);
	--i;
	while (i && ft_strchr(set, p[i]))
		--i;
	return (ft_substr(p, 0, i + 1));
}
