/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:40:02 by alsanche          #+#    #+#             */
/*   Updated: 2021/10/14 17:59:54 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_contar(uintptr_t nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
		len += 1;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

static int	ft_hex_void(uintptr_t n, char *base)
{
	uintptr_t			point;
	int					count;
	int					len;
	char				*strnbr;

	if (n == 0)
	{
		count = write (1, "0", 1);
		return (count);
	}
	len = ft_contar(n);
	strnbr = malloc(sizeof(char) * len + 1);
	if (!strnbr)
		return (0);
	strnbr[len] = '\0';
	while (len--)
	{
		point = n % 16;
		strnbr[len] = base[point];
		point = n / 16;
		n = point;
	}
	count = ft_putstr(strnbr);
	free(strnbr);
	return (count);
}

int	ft_change(void *str, char *base)
{
	int				count;
	uintptr_t		str2;

	str2 = (uintptr_t)str;
	count = ft_hex_void(str2, base);
	return (count);
}
