/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:27:32 by sperron           #+#    #+#             */
/*   Updated: 2024/09/09 09:29:08 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_byte	*ptsrc;
	t_byte	*ptdest;

	if (dest == src)
		return (dest);
	i = 0;
	ptsrc = (t_byte *)src;
	ptdest = (t_byte *)dest;
	while (i < n)
	{
		ptdest[i] = ptsrc[i];
		i++;
	}
	return ((void *)ptdest);
}
