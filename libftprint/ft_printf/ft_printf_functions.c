/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:14:43 by pafuente          #+#    #+#             */
/*   Updated: 2025/01/10 12:37:12 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int character)
{
	write(1, &character, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (! str)
		return (write (1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	return (write (1, str, len));
}
