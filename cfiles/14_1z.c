#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int status;
	pid_t parent;

	if(argc != 2){
		printf("Not 2 arguments!");
		return 1;
	}

	pid_t newproc = fork();

	if( newproc == -1){
		perror("Error");
		return 2;
	}

	if( newproc == 0){
		execvp(argv[1], &argv[1]);

		perror("Exec failed");
		exit(42);
	}
	else {
		parent = wait(&status);
		printf("Id: %d\n", parent);
		printf("Exit code: %d\n", status);
	}	

	return 0;
}
