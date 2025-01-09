/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:08:25 by pafuente          #+#    #+#             */
/*   Updated: 2025/01/09 11:05:47 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc, free
#include <unistd.h> // write
#include <stdarg.h> // va_start, va_arg...
#include <stdio.h> // real printf


int	ft_putchar(int character)
{
	write(1, &character, 1);
	return (1);
}

int	ft_printf_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	// else if (format == 's')
	// 	return (ft_putstr(va_arg(args, char *)));
	// else if (format == 'p')
	// 	return (ft_putpointer(va_arg(args, unsigned long long)));
	// else if (format == 'd' || format == 'i')
	// 	return (ft_putnumb(va_arg(args, int)));
	// else if (format == 'u')
	// 	return (ft_putunsigned(va_arg(args, unsigned int)));
	// else if (format == 'x' || format == 'X')
	// 	return (ft_puthexadecimal(va_arg(args, unsigned int), format));
	// else if (format == '%')
	// 	return (ft_putchar('%'));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	if (!format)
		return (-1);

}

int main ()
{
    ft_putchar('H');
	return 0;
}