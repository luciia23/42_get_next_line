/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:17:53 by lcollado          #+#    #+#             */
/*   Updated: 2023/01/18 13:36:39 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
static int BUFFER_SIZE = 5;
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
/*Utilizamos variables estáticas para que su valor se mantenga en las diferentes llamadas a la función*/
char    *get_next_line(int fd)
{
    static char     *buffer;
    static int      bytes_count;
    static int      index;
    char            *line;
    int                 i;

    index = 0;
    i = 0;
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    while (1)
    {
        printf("\nEntra aquí\n");
        bytes_count = read(fd, buffer, BUFFER_SIZE);
        printf("\nBytes count dentro: %d", bytes_count);
        if (bytes_count < 0){
            free(buffer);
            return (NULL);
        }
        if (bytes_count == 0)
            break ;
        index += bytes_count;
        printf("\nBuffer: %s", buffer);
    }
    printf("\nBytes count fuera: %d", bytes_count);
    printf("\nIndex estático: %d", index);
    printf("\n-----------\n ");
    line = "aaaaaa";
    return (line);

}

int main(int argc, char **argv){
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}