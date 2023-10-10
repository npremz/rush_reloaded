/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:44:40 by npremont          #+#    #+#             */
/*   Updated: 2023/10/10 19:03:51 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_sameletters(char *to_find, char *answer)
{
	int	rep;
	int	i;
	int	j;
	int	*tab;

	tab = (int *)malloc(sizeof(int) * strlen(to_find));
	if (tab == 0)
		return (-1);
	i = 0;
	rep = 0;
	while (answer[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0')
		{
			if (answer[i] == to_find[j] && tab[j] != 1)
			{
				tab[j] = 1;
				rep++;
				break;
			}
			j++;
		}
		i++;
	}
	free(tab);
	return (rep);
}

int	ft_samespot(char *to_find, char *answer)
{
	int	i;
	int	rep;

	i = 0;
	rep = 0;
	while (to_find[i])
	{
		if (to_find[i] == answer[i])
			rep++;
		i++;
	}
	return (rep);
}

int	*ft_checkword(char *to_find, char *answer)
{
	int	*tab;

	tab = (int *)malloc(sizeof(int) * 2);
	if (tab == NULL)
		return (NULL);
	tab[0] = ft_samespot(to_find, answer);
	tab[1] = ft_sameletters(to_find, answer) - tab[0];
	return (tab);
}

// int main(void) {
//   int *res = ft_checkword("pomme", "emmop");
//   printf("place :%d %d\n", res[0], res[1]);
//   return 0;
// }