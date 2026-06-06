#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int status;
	pid_t parent;

	printf("The id of the process: %d\n", getpid());

	printf("The id of the parent process: %d\n", getppid());

	pid_t res = fork();

	if( res == -1){ 
		perror("Error!");
		return 1;
	}

	if( res == 0){
		printf("The process is executed by the child\n");
		printf("Child process id: %d\n", res);
		printf("The current id: %d\n", getpid());
		printf("The current parent's id: %d\n", getppid());
		exit(42);
	}
	else { 
		printf("The process is executed by the parent\n");
		parent = wait(&status);
		
		printf("Parent process id: %d\n", res);
		printf("The current id: %d\n", getpid());
		printf("The current parent's id: %d\n", getppid());

		printf("The id of parent: %d\n", parent);
		printf("The exit code: %d\n", status);
	}

	return 0;
}

