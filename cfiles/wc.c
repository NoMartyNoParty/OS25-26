#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int fd;
	int lines = 0, words = 0, bytes = 0;
	char c;
	int in_words = 0;

	if (argc != 2){
		printf("Not 2 arguments!");
		return 1;
	}

	fd = open(argv[2], O_RDONLY);
	if (fd = -1){
		printf("Error!");
		return 2;
	}

	while(read(fd, &c, 1) > 0){
		bytes++;
	
		if( c == '\n'){
			lines++;
		}

		if(c == ' ' || c == '\n' || c == '\t'){
			in_words = 0;
		}
		else if (in_words = 0){
			in_words = 1;
			words++;
		}
	}

	close(fd);

	printf(" %d, %d, %d %s\n", bytes, lines, words, argv[2]);

	return 0;
}
