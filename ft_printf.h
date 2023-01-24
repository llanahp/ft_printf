/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:47:47 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/08 11:47:48 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

# define DECIMAL "0123456789"
# define HEX "0123456789abcdef"
# define HEXMAY "0123456789ABCDEF"

static int	do_number(int n);
static int	do_string(char *cad);
static int	do_char(int cha);

#endif