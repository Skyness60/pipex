/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:12:51 by sperron           #+#    #+#             */
/*   Updated: 2024/09/09 09:27:11 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*dest;

	size = (ft_strlen(s) + 1);
	dest = malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s, size);
	return (dest);
}

// int main(void)
// {
//     printf("%s", ft_strdup("test"));
//     printf("\n");
//     printf("%s", strdup("test"));
//     printf("\n");
//     return (0);
// }