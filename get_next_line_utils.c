/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:37:36 by lcollado          #+#    #+#             */
/*   Updated: 2023/03/03 16:40:56 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (i < len && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return (&((char *)s)[i]);
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*str;
	int		i;

	len = ft_strlen((char *)s);
	str = (char *) malloc (sizeof(char) * (len + 1));
	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strdup(s2));
	}
	s = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	free(s1);
	return (s);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	void			*s;
	unsigned int	n;
	unsigned int	i;

	n = 0;
	if (nmeb == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	n = nmeb * size;
	s = malloc(n);
	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
	return (s);
}
