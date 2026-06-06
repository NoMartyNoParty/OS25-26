#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int status;

	if(argc != 3){
		printf("Not 3 arguments");
		return 1;
	}

	pid_t pit1 = fork();

	if(pit1 == -1){
		perror("Error!");
		return 2;
	}

	if(pit1 == 0){
		execlp(argv[2],argv[2], NULL);
		perror("Exec failed!");
		exit(1);
	}

	wait(&status);

	if(status == 0){
		pid_t pit2 = fork();
		if(pit2 == -1){
			perror("Error!");
			return 3;
		}
		
		if(pit2 == 0){
			execlp(argv[3], argv[3], NULL);
			perror("Error!");
			exit(1);
		}
		wait(&status);
	}	
		
	return 0;
}
