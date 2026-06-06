#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	int fd;
	char buffer;
	ssize_t n_read;

	if( argc != 2){
		printf("Not 2 arguments\n");
		return 1;
	}

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(fd == -1){
		perror("Cannot open file");
		return 2;
	}

	while ((n_read = read(0, &buffer, 1)) > 0 ){
		if(write(1, &buffer, n_read) != n_read){
			perror("Error");
			close(fd);
			return 3;
		}
		if(write(fd, &buffer, n_read) != n_read){
			perror("Error");
			close(fd);
			return 4;
		}
	}

	close(fd);
	return 0;
}
