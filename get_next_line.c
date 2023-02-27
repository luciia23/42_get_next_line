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
char *read_line(int fd,char *buffer, char *remainder)
{
    int 	bytes_read;

    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(remainder, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0)
            break;
        if (bytes_read < 0)
        {
			free(remainder);
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        remainder = ft_strjoin(remainder, buffer);
    }
    free(buffer);
    return (remainder);
}

//Obtiene la linea antes del \n
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
	if (remainder[i] == '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

//mover la posición para después del salto de línea, y que siga imprimiendo desde ahí
//comprobar esta función, último bloque
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

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	//buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	remainder = read_line(fd, buffer, remainder);
	if(!remainder || *remainder == '\0')
		return (NULL);
	line = get_line(remainder);
	remainder = move_position(remainder);
	//printf("REMAINDER -->%s\n", remainder);
	return (line);
}

/*int main(){
	int fd;
	char *line;

	fd = open("41_with_nl", O_RDONLY);
	line = get_next_line(fd);
	//printf("primera llamada ---->%s\n", line);
	while(line)
	{
		printf("----->%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
		
	return (0);
}*/