/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:35:11 by alsanche          #+#    #+#             */
/*   Updated: 2021/10/20 17:54:41 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n, int init)
{
	static int	count;

	if (init == 0)
		count = 0;
	if (n > 9)
	{
		ft_putunbr(n / 10, 1);
		ft_putunbr(n % 10, 1);
	}
	else
	{
		ft_putchar(n + 48);
		++count;
	}
	return (count);
}
