/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:21:50 by vacsargs          #+#    #+#             */
/*   Updated: 2023/04/26 17:37:24 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int	ft_chek(char *s)
{
	char	*a;
	int		i;
	int		j;

	a = malloc(sizeof(char) * 8);
	i = 0;
	j = 3;
	a = "map.ber";
	while (s[i] != '.')
		i++;
	if (s[i] == '.')
	{
		while (s[i] && a[j])
		{
			if (s[i] == a[j])
			{
				i++;
				j++;
			}
			else
				break ;
		}
	}
	else
		return (0);
	if (s[i] == '\0' && a[j] == '\0')
	{
		i = 0;
		while (s[i] != '.' && a[i] != '.')
		{
			if(s[i] == a[i])
			i++;
			else
				return (0);
		}
		
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	char *res;
		
	line = NULL;
	res = NULL;
	if (argc == 2)
	{
		if (ft_chek(argv[1]))
		{
			ft_printf("OK");
		}
		else
		{
			ft_printf("Error");
			// exit ;
		}
	}
	else
		ft_printf("Error");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error");
		exit (0);
	}
	while (1)
	{
			line = get_next_line(fd);
			if(line == NULL)
				break;
			res = ft_strjoin(res,line);
	}	ft_printf("%s", res);
}
