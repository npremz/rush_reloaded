/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:16:46 by npremont          #+#    #+#             */
/*   Updated: 2023/10/11 10:38:04 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	**ft_parsing(char *file);
int		*ft_checkword(char *to_find, char *answer);

void	ft_gameinput(int word_size, char **answer, char *word)
{
	int	i;

	printf("Enter a combination of %d letters: ", word_size);
	scanf("%s", *answer);
	if (strlen(*answer) != strlen(word))
		printf("Your answer doesn't match the word length...\n");
	else
	{
		i = 0;
		while ((*answer)[i] != '\0')
		{
			if ((*answer)[i] == word[i])
				printf("\033[0;32m%c\033[0m", (*answer)[i]);
			else
				printf("%c", (*answer)[i]);
			i++;
		}
		printf("\n");
		printf("%d well-placed letters\n", ft_checkword(word, *answer)[0]);
		printf("%d misplaced letters\n", ft_checkword(word, *answer)[1]);
	}
}

int	ft_checkargs(int ac)
{
	if (ac != 2)
	{
		printf("Wrong argument input! This program take only one argument.\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int		answer_count;
	char	*answer;
	char	**parsing;
	int		j;

	parsing = ft_parsing(av[1]);
	if (ft_checkargs(ac) == 0)
		return (0);
	answer_count = 0;
	j = 1;
	while (++answer_count < 21 && strcmp(answer, parsing[0]) != 0)
	{
		answer = malloc(300);
		if (answer == NULL)
			return (1);
		ft_gameinput(strlen(parsing[0]), &answer, parsing[0]);
		if (answer_count % 5 == 0 && strcmp(answer, parsing[0]) != 0)
			printf("%s\n", parsing[j++]);
	}
	if (strcmp(answer, parsing[0]) == 0)
		printf("You won! Well played.\n");
	else
		printf("Have you even tried?? You lost !\n");
	free(answer);
	return (0);
}
