/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:07:42 by alsanche          #+#    #+#             */
/*   Updated: 2021/10/20 17:18:00 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	verifik2(const char *flag, int x, va_list args)
{
	int	count;

	count = 0;
	if (flag[x + 1] == 'i')
		count = ft_putnbr(va_arg(args, int), 0);
	else if (flag[x + 1] == 'u')
		count = ft_putunbr(va_arg(args, unsigned int), 0);
	else if (flag[x + 1] == 'x')
		count = ft_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (flag[x + 1] == 'X')
		count = ft_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (flag[x + 1] == '%')
		write(1, "%", ++count);
	return (count);
}

static int	verify(const char *flag, int x, va_list args)
{
	int	count;

	count = verifik2(flag, x, args);
	if (flag[x + 1] == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (flag[x + 1] == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (flag[x + 1] == 'p')
	{
		write (1, "0x", 2);
		count = ft_change(va_arg(args, void *), "0123456789abcdef");
		count += 2;
	}
	else if (flag[x + 1] == 'd')
		count = ft_putnbr(va_arg(args, int), 0);
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		x;
	int		out;

	va_start(args, input);
	x = 0;
	out = 0;
	while (input[x])
	{
		if (input[x] == '%')
		{
			out += verify(input, x, args);
			x++;
		}
		else
			out += ft_putchar(input[x]);
		if (input[x] == '\0')
			return (out);
		x++;
	}
	va_end(args);
	return (out);
}
