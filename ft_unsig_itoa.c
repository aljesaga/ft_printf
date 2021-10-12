/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:37:32 by alsanche          #+#    #+#             */
/*   Updated: 2021/10/07 15:12:38 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	ft_exp(long nbr)
{	
	int	i;
	int	top;

	i = 1;
	top = -1;
	if (nbr < 0)
		nbr = -nbr;
	while ((nbr / i) > 9 && top++ < 10)
	{
		i *= 10;
	}
	return (i);
}

char	*ft_unsig_itoa(unsigned int n)
{
	int			j;
	int			exp;
	long		nbr;
	char		*str;

	nbr = n;
	str = (char *)malloc(sizeof(char) * (count(nbr) + 1));
	if (!str)
		return (NULL);
	exp = ft_exp(nbr);
	j = 0;
	if (n < 0)
	{
		str[j] = 45;
		j++;
	}
	while (exp > 0)
	{
		str[j++] = (nbr / exp % 10) + 48;
		exp /= 10;
	}
	str[j] = '\0';
	free(str);
	return (str);
}
