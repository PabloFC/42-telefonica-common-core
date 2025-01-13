/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:07:35 by pafuente          #+#    #+#             */
/*   Updated: 2025/01/13 10:30:23 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ----- Preamble -----

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_arg...
# include <stdio.h> // real printf
# include "../libft/libft.h"

// ----- Functions -----

int	ft_printf(const char *format, ...);
int	ft_putchar(int character);
int	ft_printf_format(va_list args, const char format);
int	ft_putstr(char *str);
int	ft_putnum(int n);

#endif