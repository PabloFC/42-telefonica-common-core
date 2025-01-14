/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:34:58 by pafuente          #+#    #+#             */
/*   Updated: 2025/01/14 10:44:38 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//This function calculates the number of digits in an unsigned int.

int	ft_num_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int num)
{
	char	*str;
	int		len;

	len = ft_num_len(num);
	str = (char *)malloc((len + 1) * sizeof(char ));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len --;
	}
	return (str);
}

int	ft_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	len = 0;
	if (n == 0)
	{
		len = write (1, "0", 1);
	}
	else
	{
		str = ft_utoa(n);
		if (str)
		{
			len += ft_num_len(str);
			free(str);
		}
	}
	return (len);
}

