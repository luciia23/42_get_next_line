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


char *get_line_from_remainder(char *remainder)
{
  char *line;		
  int i;

  i = 0;
  while (remainder[i] && remainder[i] != '\n')
    i++;
  line = (char *)malloc((i + 1) * sizeof(char));
  if (!line)
    return (NULL);
  i = 0;
  while (remainder[i] && remainder[i] != '\n')
  {
    line[i] = remainder[i];
    i++;
  }
  line[i] = '\0';
  return (line);
}

char *get_remainder_from_string(char *remainder)
{
  char *new_remainder;
  int i;
  int j;

  i = 0;
  while (remainder[i] && remainder[i] != '\n')
    i++;
  if (!remainder[i])
  {
    free(remainder);
    return (NULL);
  }
  new_remainder = (char *)malloc((ft_strlen(remainder) - i + 1) * sizeof(char));
  if (!new_remainder)
    return (NULL);
  i++;
  j = 0;
  while (remainder[i])
  {
    new_remainder[j] = remainder[i];
    i++;
    j++;
  }
  new_remainder[j] = '\0';
  printf("new remainder%s", new_remainder);
  free(remainder);
  return (new_remainder);
}