#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd; 
	char buffer; 
	ssize_t n_read;
	int n = 0, m = 0;


	if(argc != 2){
		printf("Not 2 arguments");
		return 1;
	}

	scanf("Enter m: %d\n", m);
	scanf("Enter n: %d\n", n);

	int counter = 0;

	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror("Error!");
		return 2;
	}

	while((n_read = read(fd, &buffer, 1)) > 0){
		if(buffer == '\n'){
			counter = 0;
		}
		else {
			counter++;
		}

		if(counter >= m && counter <= n){
			if(write(1, buffer, n_read) != 1){
				perror("Error!");
				close(fd);
				return 3;
			}
		}
	}

	close(fd);

	return 0;
}
