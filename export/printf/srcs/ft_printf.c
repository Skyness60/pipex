/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:08:47 by sperron           #+#    #+#             */
/*   Updated: 2024/05/29 13:29:01 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static int	conv(char form, va_list args)
{
	if (form == 'c')
		return (ft_putchar((char) va_arg(args, int)));
	else if (form == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (form == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (form == 'd' || form == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (form == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (form == 'x' || form == 'X')
		return (ft_puthexa(form, va_arg(args, unsigned int)));
	else if (form == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		nb;

	va_start(args, format);
	i = 0;
	nb = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			nb += conv(format[i++ + 1], args);
		else
			nb += ft_putchar(format[i]);
		i++;
	}
	return (va_end(args), nb);
}
