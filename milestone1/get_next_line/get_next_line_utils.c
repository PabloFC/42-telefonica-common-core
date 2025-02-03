/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:22:32 by pafuente          #+#    #+#             */
/*   Updated: 2025/02/03 13:37:55 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//returns the length of a given string s

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

//locate the first occurrence of a character c in the string s.
//It returns a pointer to the first occurrence of the character in the string, 
//or NULL if the character is not found.

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (NULL);
}

// ft_memcpy is designed to copy n bytes of data 
// from a source memory location src to a destination memory location dest

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr_dest;
	char	*ptr_src;
	size_t	i;

	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

//The function ft_strdup is designed to create
// a duplicate of the input string s.
char	*ft_strdup(char *s)
{
	size_t	len;
	char	*new_str;

	len = (ft_strlen(s) + 1);
	new_str = malloc(len);
	if (new_str != NULL)
	{
		ft_memcpy(new_str, s, len);
	}
	return (new_str);
}

// concatenates two strings (s1 and s2)
// and return the resulting new string

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	joined_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined_str)
		return (NULL);
	i = -1;
	while (s1[++i])
		joined_str[i] = s1[i];
	j = -1;
	while (s2[++j])
		joined_str[i + j] = s2[j];
	joined_str[i + j] = '\0';
	free(s1);
	return (joined_str);
}

// int main ()
// {
// 	 char str1[] = "Hola, ";
//     char str2[]="mundo";

// 	char *result = ft_strjoin(str1, str2);

//     // Imprimimos el resultado
//     if (result) {
//         printf("%s\n", result);  // Imprime "Hola, mundo"
//         free(result);  // Liberamos la memoria reservada
//     }
// 	return 0;
// }