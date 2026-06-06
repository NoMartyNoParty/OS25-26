#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int m = 0, n = 0;
	char buffer;
	ssize_t n_read;
	int fd;


	printf("Enter m: ");
	scanf("%d", &m);
	
	printf("\nEnter n: ");
	scanf("%d", &n);

	if (argc != 3){
		printf("Not 3 arguments!\n");
		return 1;
	}

	fd = open(argv[2], O_RDONLY);
	
	if( fd == -1){
		perror("Error!");
		return 2;
	}
	
	int currentpos = 0;

	while((n_read = read(fd, &buffer, 1)) > 0){
		currentpos++;
		if(buffer == '\n'){
			write(1, &buffer, 1);
			currentpos = 0;
			continue;
		}

		if ( currentpos >= m && currentpos <= n){
			if(write(1, &buffer, 1) != 1){
				perror("Error");
				close(fd);
				return 3;
			}
		}

	}

	close(fd);
	
	return 0;
}
