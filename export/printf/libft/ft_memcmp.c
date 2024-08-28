/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:12:57 by sperron           #+#    #+#             */
/*   Updated: 2024/05/23 14:48:03 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t len)
{
	const unsigned char	*a;
	const unsigned char	*b;

	if (!p1 || !p2)
		return (NULL);
	a = (const unsigned char *) p1;
	b = (const unsigned char *) p2;
	while (len-- > 0)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}
