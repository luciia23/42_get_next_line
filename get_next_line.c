/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lcollado <lcollado@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/14 13:17:53 by lcollado		  #+#	#+#			 */
/*   Updated: 2023/02/07 16:48:25 by lcollado		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
/*Utilizamos variables estáticas para que su valor se mantenga en las diferentes llamadas a la función*/

//Lee el archivo hasta llegar a un salto de línea y lo guarda en la estática
/*tengo que ver que cuando el remainder esté vacío en las siguientes llamadas*/
//bucle infinito
char	*read_line(int fd, char *buffer, char *remainder)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
	}
	free(buffer);
	printf("remainder.%s\n", remainder);
	return (remainder);
}

char	*get_line(char *remainder)
{
	char	*line;
	int		i;

	i = 0;
	while (remainder[i] != '\n' && remainder[i] != 0)
		i++;
	line = (char *)ft_calloc(sizeof(char), (i +1));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] != '\n' && remainder[i] != 0)
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	printf("line.%s\n", line);
	return (line);
}
//mover la posición para después del salto de línea, y que siga imprimiendo desde ahí
char	*move_position(char *remainder)
{
	int	i;

	i = 0;
	while (remainder[i] != '\n' && remainder[i] != 0)
		i++;
	i++;
	printf("prueba -->%s-\n", &remainder[i]);
	return (&remainder[i]);	
}

char	*get_next_line(int fd)
{
	static char	 *remainder;
	char			*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	remainder = read_line(fd, buffer, remainder);
	line = get_line(remainder);
	remainder = move_position(remainder);
	printf("REMAINDER -->%s\n", remainder);
	return (line);
}

int main(int argc, char *argv[]){
	int fd;
	char *line;

	fd = open("texto.txt", O_RDONLY);
	line = get_next_line(fd);
	// printf("primera llamada ---->%s\n", line);
	while(line)
	{
		printf("----->%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
		
	return (0);
}
