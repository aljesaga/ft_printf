/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:35:11 by alsanche          #+#    #+#             */
/*   Updated: 2021/10/20 17:20:07 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int init)
{
	static int	count;

	if (init == 0)
		count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", (count += 11));
		return (count);
	}
	if (n < 0)
	{
		write(1, "-", ++count);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, 1);
		ft_putnbr(n % 10, 1);
	}
	else
	{
		ft_putchar(n + 48);
		count++;
	}
	return (count);
}
