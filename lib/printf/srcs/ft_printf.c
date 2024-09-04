/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:08:47 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 00:00:30 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	conv(char form, va_list args, int fd)
{
	if (form == 'c')
		return (ft_putchar((char) va_arg(args, int), fd));
	else if (form == 's')
		return (ft_putstr(va_arg(args, char *), fd));
	else if (form == 'p')
		return (ft_putpointer(va_arg(args, void *), fd));
	else if (form == 'd' || form == 'i')
		return (ft_putnbr(va_arg(args, int), fd));
	else if (form == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int), fd));
	else if (form == 'x' || form == 'X')
		return (ft_puthexa(form, va_arg(args, unsigned int), fd));
	else if (form == '%')
		return (ft_putchar('%', fd));
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
			nb += conv(format[i++ + 1], args, 1);
		else
			nb += ft_putchar(format[i], 1);
		i++;
	}
	return (va_end(args), nb);
}

int	ft_dprintf(int fd, const char *format, ...)
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
			nb += conv(format[i++ + 1], args, fd);
		else
			nb += ft_putchar(format[i], fd);
		i++;
	}
	return (va_end(args), nb);
}