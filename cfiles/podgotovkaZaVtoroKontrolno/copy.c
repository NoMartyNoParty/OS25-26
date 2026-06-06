#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int fd1, fd2;
	char buffer;
	ssize_t n_read;


	if(argc != 3){
		printf("Not 3 arguments");
		return 1;
	}

	fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1){
		perror("Error!");
		return 2;
	}

	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd2 == -1){
		perror("Error!");
		return 3;
	}

	while((n_read = read(fd1, &buffer, sizeof(buffer))) > 0){
		if(write(fd2, &buffer, 1) != n_read){
			perror("Error!");
			close(fd1);
			close(fd2);
			return 4;
		}
	}

	close(fd1);
	close(fd2);

	return 0;
}
