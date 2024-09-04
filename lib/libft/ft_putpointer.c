/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:43:52 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 01:01:14 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printadress(const unsigned long n, int fd)
{
	if (n / 16)
		return (ft_printadress(n / 16, fd) + ft_printadress(n % 16, fd));
	else if (!(n / 10))
		ft_putchar(n + '0', fd);
	else
		ft_putchar((char) n - 10 + 'a', fd);
	return (1);
}

int	ft_putpointer(void *adress, int fd)
{
	if (!adress)
		return (ft_putstr("(nil)", fd));
	ft_putstr("0x", fd);
	return (2 + ft_printadress((unsigned long) adress, fd));
}
