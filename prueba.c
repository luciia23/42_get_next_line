#include <stdio.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i] != 0)
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *s;
    int     len;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    s = (char *)malloc(sizeof(char) * (len + 1));
    if (!s)
        return (NULL);
    while (s[i])
    {
        s[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s[i] = s2[j++];
        i++;
    }
    s[i] = '\0';
    return (s);
}

int main(){
	char s1[] = "peanut";
	char s2[] = "butter";

	printf("%s\n", ft_strjoin(s1, s2));

	return 0;
}