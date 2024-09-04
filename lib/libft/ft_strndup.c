/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:12:52 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 00:52:49 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int n)
{
	char	*dup;

	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	ft_strncpy(dup, str, n);
	dup[n] = '\0';
	return (dup);
}

