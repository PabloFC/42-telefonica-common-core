/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:46:46 by pafuente          #+#    #+#             */
/*   Updated: 2025/01/16 10:08:47 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function calculates the length (number of digits) 
// of a number in its hexadecimal representation.

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_printhexa(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_printhexa(num / 16, format);
		ft_printhexa(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_puthexa(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_printhexa(num, type);
	return (ft_hexlen(num));
}
