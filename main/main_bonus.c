#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd1;
    int fd2;
    char    *gnl;

    fd1 = open("files/texto.txt", O_RDONLY);
    fd2 = open("files/big_line_no_nl", O_RDONLY);

    gnl = get_next_line(fd1);
	printf("FD01 | First Line:\t%s\n", gnl);
	free(gnl);
	gnl = get_next_line(fd2);
	printf("FD02 | First Line:\t%s\n", gnl);
	free(gnl);
	gnl = get_next_line(fd1);
	printf("FD01 | Second Line:\t%s\n", gnl);
	free(gnl);
	gnl = get_next_line(fd2);
	printf("FD02 | Second Line:\t%s\n", gnl);
	free(gnl);
	gnl = get_next_line(fd1);
	printf("FD01 | Third Line:\t%s\n", gnl);
	free(gnl);
	gnl = get_next_line(fd2);
	printf("FD02 | Third Line:\t%s", gnl);
	free(gnl);
		
	return (0);
}