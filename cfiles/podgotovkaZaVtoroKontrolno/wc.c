#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd;
	char buffer;
	ssize_t n_read;

	if(argc != 2){
		printf("Not 2 arguments");
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror("Error!");
		return 2;
	}

	int counterLines = 0;
	int bytes = 0;
	int wordFlag = 0;
	int counterWords = 0;

	while((n_read = read(fd, &buffer, 1)) > 0){
		bytes++;
		
		if(buffer == '\n'){
			counterLines++;
		}

		if(buffer == ' ' || buffer == '\n' || buffer == '\t'){
			wordFlag = 0;
		}
		else if(wordFlag == 0){
			wordFlag = 1;
			counterWords++;
		}
	}	

	printf("Bytes: %d\n", bytes);
	printf("Words: %d\n", counterWords);
	printf("Lines: %d\n", counterLines);
	
	close(fd);

	return 0;
}
