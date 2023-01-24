/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_disc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:40:33 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/09 13:40:40 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	do_number(int n)
{
	char	*num;
	int		i;
	char	c;
	int		len;

	num = ft_itoa(n);
	i = 0;
	if (num == NULL)
		return (i);
	len = ft_strlen(num);
	while (len)
	{
		c = num[i];
		write(1, &c, 1);
		i++;
		len--;
	}
	return (i);
}

static int	do_string(char *cad)
{
	int		i;
	char	c;

	i = 0;
	while (cad[i])
	{
		c = cad[i];
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	do_char(int cha)
{
	char	c;

	c = (int)cha;
	write(1, &c, 1);
	return (1);
}
