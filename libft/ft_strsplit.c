/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:50:42 by spuyet            #+#    #+#             */
/*   Updated: 2014/01/12 19:52:57 by spuyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_words(char const *s, char c)
{
	int		words;
	int		i;
	int		flag;

	words = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			words++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	return (words);
}

static int		letters(char const *s, char c, int count)
{
	int	letters;

	letters = 0;
	while (s[count] != c && s[count] != '\0')
	{
		letters++;
		count++;
	}
	return (letters);
}

static int		skip_char(char const *s, char c, int count)
{
	while (s[count] == c && s[count] != '\0')
		count++;
	if (s[count] == '\0')
		return (-1);
	return (count);
}

static void		fill_tab(char **tab, char c, char const *s)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (s[count] != '\0' && (skip_char(s, c, count) != -1))
	{
		j = 0;
		count = skip_char(s, c, count);
		tab[i] = (char *) malloc((letters(s, c, count) + 1) * sizeof(char));
		if (tab[i] != NULL)
		{
			while (s[count] != c && s[count] != '\0')
			{
				tab[i][j] = s[count];
				j++;
				count++;
			}
			tab[i][j] = '\0';
			i++;
		}
	}
	tab[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;

	tab = NULL;
	if (s)
	{
		words = count_words(s, c);
		tab = (char **) malloc((words + 1) * sizeof(char *));
		if (tab)
			fill_tab(&(*tab), c, s);
	}
	return (tab);
}
