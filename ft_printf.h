/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:11:04 by alsanche          #+#    #+#             */
/*   Updated: 2021/10/12 20:05:08 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int			ft_printf(const char *input, ...);
int			ft_hex(unsigned int n, char *base);
char		*ft_unsig_itoa(unsigned int n);
int			ft_change(void *str, char *base);
int			ft_putchar(char c);
size_t		ft_strlen(const char *c);
int			ft_putstr(char *s);
char		*ft_itoa(int n);

#endif
