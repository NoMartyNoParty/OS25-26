#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	int fd;
	char buffer;
	ssize_t n_read;

	if ( argc < 2){
		printf("Not enough arguments\n");
		return 1;
	}
	

	for(int i = 1; i < argc; i++){
		fd = open(argv[i], O_RDONLY);
		if(fd == -1){
			perror("Error!");
			continue;
		}
		
		while((n_read = read(fd, &buffer, 1)) > 0){
			if(write(1, &buffer, n_read) != n_read){
				perror("Error!");
				close(fd);
				return 3;
			}
		}
		close(fd);
	}

	return 0;
} 
