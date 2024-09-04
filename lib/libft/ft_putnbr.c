/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:43:01 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 01:01:09 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10, fd);
	}
	count += ft_putchar(n % 10 + '0', fd);
	return (count);
}
