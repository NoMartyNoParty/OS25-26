#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	int status;
	pid_t parent;

	printf("Process' id: %d\n", getpid());
	printf("Parent's process id: %d\n", getppid());

	pid_t res = fork();

	if(res == -1){
		perror("Error!");
		return 1;
	}

	if(res == 0){
		printf("Child's process: %d\n", res);
		printf("Child's process id: %d\n", getpid());
		printf("Child's parent process id: %d\n", getppid());
		
		execlp("ps", "ps", NULL);
		
		perror("Exec failed!");

		exit(2);
	}
	else { 
		printf("Parent's process: %d\n", res);
		printf("Parent's process id: %d\n", getpid());
		printf("Parent's parent process id: %d\n", getppid());

		parent = wait(&status);

		printf("Parent: %d\n", parent);
		printf("Exit code: %d\n", status);
	}

	return 0;
}
