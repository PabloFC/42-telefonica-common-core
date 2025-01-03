/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:46:06 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/23 13:05:19 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*pointer;

	pointer = (char *)s;
	while (n > 0)
	{
		*pointer = 0;
		pointer++;
		n--;
	}
}

int main()
{
    char str[] = "Hola mundo";
    printf("Antes: %s\n", str);
    ft_bzero(str, 5);
    printf("Después: ");
    for(int i = 0; i < sizeof(str); i++)
    {
        if(str[i] == '\0')
            printf("\\0");
        else
            printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}