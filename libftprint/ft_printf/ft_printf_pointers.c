/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:06:54 by pafuente          #+#    #+#             */
/*   Updated: 2025/01/16 11:38:02 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ft_count_hex_digits(unsigned long long ptr)
// {
// 	int	i;

// 	i = 0;
// 	while (ptr != 0)
// 	{
// 		i++;
// 		ptr = ptr / 16;
// 	}
// 	return (i);
// }

int	ft_printpointer_hex(unsigned long long ptr)
{
	int	len;

	len = 0;

	if (ptr >= 16)
	{
		len += ft_printpointer_hex(ptr / 16);
		len += ft_printpointer_hex(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			len += ft_putchar(ptr + 48);
		else
			len += ft_putchar(ptr - 10 + 'a');
	}
	return (len);
}

int	ft_putpointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	len = write (1, "0x", 2);
	len += ft_printpointer_hex(ptr);
	return (len);
}
