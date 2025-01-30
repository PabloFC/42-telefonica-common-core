/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:20:03 by pafuente          #+#    #+#             */
/*   Updated: 2025/01/30 12:26:39 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

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


char	*ft_strjoin_and_free(char *s1, char *s2)
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
	if (!str)
		return (NULL);
	out = ft_newline(str);
	str = ft_readline(str);
	return (out);
}


