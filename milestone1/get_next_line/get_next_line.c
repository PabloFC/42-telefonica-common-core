/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:20:03 by pafuente          #+#    #+#             */
/*   Updated: 2025/02/03 12:38:27 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// The get_next_line function is designed to read a line
//from a file descriptor fd and return it as a string.
char	*get_next_line(int fd)
{
	char		*out;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_readfile(fd, str);
	if (!str || str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	out = ft_newline(str);
	str = ft_readline(str);
	return (out);
}
