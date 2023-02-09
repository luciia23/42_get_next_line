#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while ((s[i] != 0) && (s[i] != (unsigned char)c))
		i++;
	if (s[i] == (unsigned char)c)
		return (&((char *)s)[i]);
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

int main(int argc, char **argv)
{
	int	 fd;
	char	*buffer;
	ssize_t leido;
	int i;
	//char	*line = (char *)malloc (1 * sizeof(char));

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	while(buffer[i] != '\n')
	{
		leido = read(fd, buffer, BUFFER_SIZE);
		if (leido == 0)
			break ;
		printf("\nEl número de caracteres es: %d, contenido %s", (int)leido, buffer);
	}
	printf("aaaEl número de caracteres es: %d, contenido %s", (int)leido, buffer);
	close(fd);
	/*while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
	}*/
	/*int aux;

	while (aux != 0)
	{
		aux = read(fd, buffer, BUFFER_SIZE);
	}*/
	return (0);
}


	  /*  int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);*/