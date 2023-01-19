#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

    

int main(int argc, char **argv)
{
    int     fd;
    char    buffer[20];
    //char    *line = (char *)malloc (1 * sizeof(char));

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (0);
    ssize_t leido = read(fd, buffer, 5);
    close(fd);
    printf("El número de caracteres es: %d, contenido %s", (int)leido, buffer);
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