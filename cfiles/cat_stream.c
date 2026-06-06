#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int fd;
	char buffer;
	ssize_t n_read;

	if(argc != 2){
		printf("Not 2 arguments\n");
		return 1;
	}

	fd = open(argv[3], O_WRONLY | O_CREAT | O_APPEND, 0644);

	if(fd == -1){
		perror("Error");
		return 2;
	}

	while((n_read = read (0, &buffer, 1)) > 0){
		if(write(fd, &buffer, n_read) != n_read){
			perror("Error");
			close(fd);
			return 3;
		}
	}

	close(fd);
	
	return 0;
}
