#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	pid_t parent;
	int status;

	if(argc < 2){
		printf("Not 2 arguments");
		return 1;
	}

	pid_t newProcess = fork();

	if(newProcess == -1){
		perror("Error!");
		return 2;
	}

	if(newProcess == 0){
		execvp(argv[1], &argv[1]);

		perror("Exec failed!");
		exit(4);
	}
	else {
		parent = wait(&status);

		printf("Parent: %d\n", parent);
		printf("Exit code: %d\n", status);
	}

	return 0;
}
