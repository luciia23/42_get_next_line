/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:42:56 by lcollado          #+#    #+#             */
/*   Updated: 2023/03/02 17:05:58 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>


char    *read_line(int fd, char *buffer, char **remainder)
{
    int     bytes_read;
    char    *tmp;

    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(*remainder, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0)
            break;
        if (bytes_read < 0)
        {
			free(*remainder);
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
		tmp = *remainder;
        *remainder = ft_strjoin(tmp, buffer);
    }
    free(buffer);
    return (*remainder);
}

char	*move_position(char *remainder)
{
	int	i;
	char	*new_line;
	int	j;

	i = 0;
	while (remainder[i] != '\n' && remainder[i] != 0)
		i++;
	if (ft_strchr(remainder, '\n'))
		i++;
	new_line = (char*)malloc(sizeof(char) * (ft_strlen(&remainder[i]) + 1));
	if (!new_line)
		return (NULL);
	j = 0;
	while (remainder[i + j])
	{
		new_line[j] = remainder[i + j];
		j++;
	}
	new_line[j] = '\0';
	free(remainder);
	return (new_line);	
}

char	*get_line(char *remainder)
{
	char	*line;
	int		i;

	i = 0;
	while (remainder[i] != 0 && remainder[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] != '\n' && remainder[i] != 0)
	{
		line[i] = remainder[i];
		i++;
	}
	if (ft_strchr(remainder, '\n'))
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char    *get_next_line(int fd)
{
    static char *remainder[OPEN_MAX];
    char        *line;
    char        *buffer;

    if (fd >= OPEN_MAX || BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    remainder[fd] = read_line(fd,buffer,  &remainder[fd]);
    if (!remainder[fd] || *remainder[fd] == '\0')
    {
        free(remainder[fd]);
        remainder[fd] = NULL;
        return (NULL);
    }
    line = get_line(remainder[fd]);
    remainder[fd] = move_position(remainder[fd]);
    return (line);
}

// int main(){
//     int fd1;
//     int fd2;
//     char    *gnl;

//     fd1 = open("files/texto.txt", O_RDONLY);
//     fd2 = open("files/big_line_no_nl", O_RDONLY);

//     gnl = get_next_line(fd1);
// 	printf("FD01 | First Line:\t%s\n", gnl);
// 	free(gnl);
// 	gnl = get_next_line(fd2);
// 	printf("FD02 | First Line:\t%s\n", gnl);
// 	free(gnl);
// 	gnl = get_next_line(fd1);
// 	printf("FD01 | Second Line:\t%s\n", gnl);
// 	free(gnl);
// 	gnl = get_next_line(fd2);
// 	printf("FD02 | Second Line:\t%s\n", gnl);
// 	free(gnl);
// 	gnl = get_next_line(fd1);
// 	printf("FD01 | Third Line:\t%s\n", gnl);
// 	free(gnl);
// 	gnl = get_next_line(fd2);
// 	printf("FD02 | Third Line:\t%s", gnl);
// 	free(gnl);
		
// 	return (0);
// }