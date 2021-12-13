/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:31:18 by thpham-v          #+#    #+#             */
/*   Updated: 2021/12/13 05:18:56 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab, size_t nb_words)
{
	while (nb_words >= 0)
	{
		free(tab[nb_words]);
		nb_words--;
	}
	free(tab);
	tab = NULL;
}

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j)
			nb_words++;
		i = i + j;
	}
	return (nb_words);
}

void	ft_create_tab(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j)
		{
			tab[k] = ft_substr(s, i, j);
			k++;
		}
		i = i + j;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nb_words;

	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (nb_words + 1));
	if (tab == NULL)
		return (NULL);
	ft_create_tab(s, c, tab);
	tab[nb_words] = NULL;
	return (tab);
}
