#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd;
	char buffer; 
	ssize_t n_read;

	if(argc < 2){
		printf("Not enogh arguments");
		return 1;
	}
	
	for(int i = 1; i < argc; i++){
		fd = open(argv[i], O_RDONLY);
		
		if(fd == -1){
			perror("Error");
			return 2;
		}

		while((n_read = read(fd, &buffer, 1)) > 0){
			if(write(1, &buffer, n_read) != n_read){
				perror("Error");
				close(fd);
				return 3;
			}
		}
		close(fd);
	}

	return 0;
}
