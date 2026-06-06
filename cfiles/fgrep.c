#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	int fd;
	char buffer;
	char line;
	int i = 0;
	ssize_t n_read;
	
	if(argc != 3){
		printf("Not 3 arguments");
		return 2;
	}
	
	int n = sizeof(argv[1]);

	fd = open(argv[2], O_RDONLY);

	if( fd == -1){
		perror("Cannot open file");
		return 2;
	}

	while((n_read = read(fd, &buffer, 1)) > 0){
		if(buffer == &argv[1]){
			printf("There is this type of text %s in this program", argv[1]);
			break;
			return 3;
		}
		if(write(1, &buffer, 1) != 1){
			perror("Error!");
			close(fd);
			return 4;
		}
	}	
	
	return 0;
}
