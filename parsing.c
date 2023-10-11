/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:16:58 by bschor            #+#    #+#             */
/*   Updated: 2023/10/11 10:35:00 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_init(char **tab, char *file)
{
	int		i;
	char	c[1];
	int		fd;
	int		tab_i;

	i = 0;
	tab_i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		if (c[0] == '\n')
		{
			tab[tab_i] = malloc(sizeof(char) * (i + 1));
			if (!tab[tab_i])
				return ;
			tab[tab_i][i] = 0;
			tab_i++;
			i = 0;
		}
		else
			i++;
	}
	tab[tab_i] = malloc(sizeof(char) * (i + 1));
	close(fd);
}

void	ft_dup(char **tab, char *file)
{
	int		i;
	char	c[1];
	int		fd;
	int		tab_i;

	i = 0;
	tab_i = 0;
	ft_init(tab, file);
	fd = open(file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		if (c[0] == '\n' && tab_i != 4)
		{
			tab_i++;
			i = 0;
		}
		else
		{
			tab[tab_i][i] = c[0];
			i++;
		}
	}
	close(fd);
}

char	**ft_parsing(char *file)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 5);
	if (!tab)
		return (NULL);
	tab[4] = NULL;
	ft_dup(tab, file);
	return (tab);
}
