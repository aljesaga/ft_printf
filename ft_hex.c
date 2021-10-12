/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:20:45 by alsanche          #+#    #+#             */
/*   Updated: 2021/10/12 22:38:54 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	contar(unsigned int nbr)
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

int	ft_hex(unsigned int n, char *base)
{
	int			point;
	int			count;
	int			len;
	char		*strnbr;

	if (n == 0)
	{
		count = write (1, "0", 1);
		return (count);
	}
	len = contar(n);
	strnbr = malloc(sizeof(char) * len + 1);
	if (!strnbr)
		return (0);
	strnbr[len] = '\0';
	while (len--)
	{
		point = n % 16;
		strnbr[len] = base[point];
		n /= 16;
	}
	count = ft_putstr(strnbr);
	free(strnbr);
	return (count);
}
