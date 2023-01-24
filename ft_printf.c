/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:47:40 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/08 11:47:42 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	do_base(unsigned int n, char *ER, int base)
{
	int	i;

	i = 0;
	if ((n / base) > 0)
		i = do_base((n / base), ER, base);
	write(1, &ER[n % base], 1);
	return (1 + i);
}

static int	do_percent(void)
{
	write(1, "%", 1);
	return (1);
}

static int	show(char const *cad, va_list ap)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (cad[i])
	{
		if (cad[i] != '%')
		{
			write(1, &cad[i], 1);
			i++;
			total++;
		}
		else
		{	
			if (cad[i + 1] != 0 && (cad[i + 1] == 'd' || cad[i + 1] == 'i'))
				total += do_number(va_arg(ap, int));
			if (cad[i + 1] != 0 && cad[i + 1] == 's')
				total += do_string(va_arg(ap, char *));
			if (cad[i + 1] != 0 && cad[i + 1] == 'c')
				total += do_char(va_arg(ap, int));
			/*if (cad[i + 1] != 0 && cad[i + 1] == 'p')
				total += do_pointer(va_arg(ap, int));*/
			if (cad[i + 1] != 0 && cad[i + 1] == 'u')
				total += do_base(va_arg(ap, int), DECIMAL, 10);
			if (cad[i + 1] != 0 && cad[i + 1] == 'x')
				total += do_base(va_arg(ap, int), HEX, 16);
			if (cad[i + 1] != 0 && cad[i + 1] == 'X')
				total += do_base(va_arg(ap, int), HEXMAY, 16);
			if (cad[i + 1] != 0 && cad[i + 1] == '%')
				total += do_percent();
			i = i + 2;
		}
	}
	return (total);
}

int	ft_printf(char const *cad, ...)
{
	int		n;
	va_list	ap;

	n = 0;
	va_start(ap, cad);
	n = show(cad, ap);
	va_end(ap);
	return (n);
}
