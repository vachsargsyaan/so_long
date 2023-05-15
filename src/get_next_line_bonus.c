/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:45:47 by vacsargs          #+#    #+#             */
/*   Updated: 2023/04/26 15:11:07 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free(char *remainde)
{
	free(remainde);
	return (0);
}

char	*get_filter(char *remainde)
{
	int		i;
	char	*result;

	i = 0;
	if (!remainde)
		return (0);
	while (remainde[i] && remainde[i] != '\n')
		i++;
	if (!*remainde)
		return (0);
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (0);
	i = 0;
	while (remainde[i] && remainde[i] != '\n')
	{
		result[i] = remainde[i];
		++i;
	}
	if (remainde[i] == '\n')
		result[i++] = '\n';
	result[i] = 0;
	return (result);
}

char	*get_filter2(char *remainde)
{
	int		i;
	int		size;
	char	*p;

	i = 0;
	if (!remainde)
		return (0);
	while (remainde[i] && remainde[i] != '\n')
		i++;
	if (!remainde[i])
	{
		free(remainde);
		return (0);
	}
	size = ft_strlen(remainde) - i++;
	p = malloc(sizeof(char) * (size + 1));
	if (!p)
		return (ft_free(remainde));
	size = 0;
	while (remainde[i])
		p[size++] = remainde[i++];
	p[size] = 0;
	free(remainde);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*remainde[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			byte_was_read;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		byte_was_read = read(fd, buf, BUFFER_SIZE);
		if (byte_was_read <= 0)
			break ;
		buf[byte_was_read] = '\0';
		remainde[fd] = ft_strjoin(remainde[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (byte_was_read < 0)
		return (0);
	result = get_filter(remainde[fd]);
	remainde[fd] = get_filter2(remainde[fd]);
	if (!byte_was_read && !result)
		return (ft_free(remainde[fd]));
	return (result);
}
