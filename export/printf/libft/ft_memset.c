/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:03:22 by sperron           #+#    #+#             */
/*   Updated: 2024/05/23 14:48:42 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int value, size_t count)
{
	unsigned char	*a;

	if (!p)
		return (NULL);
	a = p;
	while (count--)
		*a++ = value;
	return (p);
}
/*
#include <stdio.h>

int main()
{
	char buff[0xff];
	ft_memset(buff, 0, 0xff);
	ft_memset(buff, 'A', 20);
	ft_memset(buff + 20, 'B', 20);
	printf("%s\n", buff);
	return (0);
}
*/