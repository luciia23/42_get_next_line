#include "get_next_line.h"
#include<stdio.h>
size_t  ft_strlen(const char *str)
{
	size_t  i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 0)
	{
		printf("-%c-\n", str[i]);
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	int len = ft_strlen(s);
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
	int	 len;
	char	*str;
	int	 i;

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
	s = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!s)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
   // free(s1);
	return (s);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*s;
	int		n;
	size_t	i;
	
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