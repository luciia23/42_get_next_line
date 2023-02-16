#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i] != 0)
        i++;
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    unsigned int    i;

    i = 0;
    while ((s[i] != 0) && (s[i] != (unsigned char)c))
        i++;
    if (s[i] == (unsigned char)c)
        return (&((char *)s)[i]);
    if (c == 0)
        return ((char *)s);
    return (NULL);
}

char    *ft_strdup(const char *s)
{
    int     len;
    char    *str;
    int     i;

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

char    *ft_strndup(const char *s, size_t n)
{
    char    *str;
    int     i;

    str = (char *) malloc (sizeof(char) * (n + 1));
    i = 0;
    if (!str)
        return (NULL);
    while (i < n)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *ft_strjoin(char *s1, char *s2)
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
    free(s1);
	return (s);
}