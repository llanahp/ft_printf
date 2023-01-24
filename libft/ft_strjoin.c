/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:27:16 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/17 12:27:26 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	int		i;
	int		len_s2;

	i = 0;
	sub = NULL;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s2 = ft_strlen((char *)s2);
	sub = ft_calloc(sizeof(char), (ft_strlen((char *)s1) + len_s2 + 1));
	if (sub == NULL)
		return (NULL);
	while (*s1)
	{
		sub[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		sub[i++] = *s2;
		s2++;
	}
	sub[i] = '\0';
	return (sub);
}
