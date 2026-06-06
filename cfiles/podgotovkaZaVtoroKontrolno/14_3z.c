#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int status;

	if(argc != 3){
		printf("Not 3 arguments");
		return 1;
	}

	pid_t firstcommand = fork();

	if(firstcommand == -1){
		perror("Error!");
		return 2;
	}
	
	if(firstcommand == 0){
		execlp(argv[1], argv[1], NULL);

		perror("Exec failed!");
		exit(2);
	}

	wait(&status);

	if(status != 0){
		pid_t secondcommand = fork();

		if(secondcommand == -1){
			perror("Error!");
			return 3;
		}

		if(secondcommand == 0){
			execlp(argv[2], argv[2], NULL);

			perror("Error!");
			exit(3);
		}
		wait(&status);
	}

	return 0;
}
