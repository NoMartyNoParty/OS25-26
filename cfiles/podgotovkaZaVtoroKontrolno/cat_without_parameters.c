#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	char buffer;
	ssize_t n_read;

	while((n_read = read(0, &buffer, 1)) > 0){
		if(write(1, &buffer, n_read) != n_read){
			perror("Error!");
			return 1;
		}
	}


	return 0;
}
