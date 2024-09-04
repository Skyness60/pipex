/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:43:13 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 01:01:02 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_unsigned(n / 10, fd);
	}
	count += ft_putchar(n % 10 + 48, fd);
	return (count);
}
