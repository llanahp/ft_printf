/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:51:43 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/13 15:53:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (words);
}

static char	*store_word(char	*s, int i, char c, char *splt)
{
	int	j;

	j = i;
	while (s[j] && s[j] != c)
	{
		j++;
	}
	splt = (char *)malloc(sizeof(char) * ((j - i) + 1));
	if (!splt)
		return (0);
	j = 0;
	while (s[i] && s[i] != c)
	{
		splt[j] = s[i];
		i++;
		j++;
	}
	splt[j] = '\0';
	return (splt);
}

char	**ft_split(char const *s, char c)
{
	char	**splt;
	int		words;
	int		i;

	i = 0;
	words = 0;
	splt = NULL;
	if (s == NULL)
		return (NULL);
	splt = (char **)malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!splt)
		return (0);
	while (s[i])
	{
		if (s[i] && ((unsigned char *)s)[i] != (unsigned char)c)
			splt[words] = store_word((char *)s, i, c, splt[words]);
		if (s[i] && ((unsigned char *)s)[i] != (unsigned char)c)
			words++;
		while ((char )s[i] && (char )s[i] != c)
			i++;
		while ((char )s[i] && (char )s[i] == c)
			i++;
	}
	splt[words] = NULL;
	return (splt);
}
