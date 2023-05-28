/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:21:50 by vacsargs          #+#    #+#             */
/*   Updated: 2023/05/28 21:00:23 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	ft_printf("Error");
	system("leaks so_long");
	exit (1);
}

void	ft_eva(char **s)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (s[++j + 1] != NULL)
	{
		i = -1;
		while (s[j][++i])
		{
			if (s[j][i] != '1' && s[j][i] != '0' && s[j][i] != 'C'
				&& s[j][i] != 'E' && s[j][i] != 'P'
					&& s[j][i] != 'V' && s[j][i] != 'M')
				ft_error();
			if (s[j][i] == 'P' && flag == 0)
				flag = 1;
			else if (s[j][i] == 'P' && flag == 1)
				ft_error();
		}
	}
	i = -1;
	while (s[j][++i])
		if (s[j][i] != '1')
			ft_error();
}

void	ft_help(char *res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] == '\n' && res[i + 1] == '\n')
			ft_error();
		i++;
	}
}

void	ft_chek(char *s)
{
	char	*a;

	a = ".ber";
	while (*s != '.')
		s++;
	if (*s == '.')
	{
		while (*s && *a)
		{
			if (*s == *a)
			{
				s++;
				a++;
			}
			else
				break ;
		}
	}
	else
		ft_error();
	if (*s == '\0' && *a == '\0')
		return ;
	ft_error();
}

int	main(int argc, char **argv)
{
	int			fd;
	char		*tmp;
	t_gamestate	game;

	game.newwin = 1;
	game.x = 1;
	game.line = NULL;
	game.res = NULL;
	game.count = 0;
	game.madara_count = 0;
	if (argc == 2)
		ft_chek(argv[1]);
	else
		ft_error();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	ft_ft(&game, fd);
	tmp = game.res;
	game.res = ft_strtrim(game.res, "\n");
	free(tmp);
	ft_help(game.res);
	game.map = ft_split(game.res, '\n');
	ft_call(&game);
	return (0);
}
