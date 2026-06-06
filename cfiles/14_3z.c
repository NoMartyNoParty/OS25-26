#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int status;

	if(argc != 3){
		printf("Not 3 arguments");
		return 1;
	}

	pid_t pid1 = fork();

	if(pid1 == -1){
		perror("Error");
		return 2;
	}

	if(pid1 == 0){
		execlp(argv[1], argv[1], NULL);
		perror("Exec failed");
		exit(1);
	}

	wait(&status);

	if(status != 0){
		pid_t pid2 = fork();
		if(pid2 == -1){
			perror("Error!");
			return 3;
		}
		if(pid2 == 0){
			execlp(argv[2], argv[2], NULL);
			perror("Exec failed");
			exit(1);
		}
		wait(&status);
	}
	
	return 0;
}
