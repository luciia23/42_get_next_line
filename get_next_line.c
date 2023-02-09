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

static char	*get_line(int fd, char *buffer, char *remainder)
{
	int bytes_read;

	bytes_read = 1;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytes_read < 0)
		{
			free(remainder);
			remainder = NULL;
			return (remainder);
		}
		remainder = ft_strjoin(remainder, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	printf("temp -> %s\n", remainder);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	 *remainder;
	char			*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	remainder = NULL;
	line = get_line(fd, buffer, remainder);
	free(buffer);
	buffer = NULL;
	return (line);
}

int main(int argc, char **argv){
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd))!= NULL)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
		
	return (0);
} 

/*int main(){
	int fd;
	char *line;

	fd = open("texto.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	
	//free(line);
	close(fd);
		
	return (0);
}*/

/*char	*get_next_line(int fd)
{
	static char	 *buffer;
	static ssize_t	 bytes_count;
	static int	  index;
	char			*line;
	int				 i;

	index = 0;
	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_strchr(buffer, '\n'))
	{
		printf("\nEntra aquí\n");
		bytes_count = read(fd, buffer, BUFFER_SIZE);
		printf("\nBytes count dentro: %zd", bytes_count);
		if (bytes_count < 0){
			free(buffer);
			return (NULL);
		}
		if (bytes_count == 0)
			break ;
		index += bytes_count;
		printf("\nBuffer: %s", buffer);
	}
	printf("\nBytes count fuera: %zd", bytes_count);
	printf("\nIndex estático: %d", index);
	printf("\n-----------\n ");
	line = "aaaaaa";
	return (line);

}*/