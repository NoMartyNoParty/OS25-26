#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int status;
	pid_t parent;

	printf("The current process id: %d\n", getpid());
	printf("The current parent process id: %d\n", getppid());

	pid_t res = fork();

	if(res == -1){
		perror("Error!");
		return 1;
	}

	char command;

	if(res == 0){
		printf("The process is executed by the child\n");

		printf("The child id: %d\n", res);
		printf("Current child process: %d\n" getpid());
		printf("Current child parent process: %d\n" getppid());
		int result = execlp("ps", "ps", NULL);

		perror("Error\n");
		exit(42);
	}
	else {
		printf("The process is executed by the parent\n");

		printf("The parent is: %d\n", res);
		printf("Current parent process: %d\n", getpid());
		printf("Current parent parent process: %d\n", getppid());

		parent = wait(&status);

		printf("The id of the parent: %d\n", parent);
		printf("The exit code: %d\n", status);
	}

	return 0;
}
