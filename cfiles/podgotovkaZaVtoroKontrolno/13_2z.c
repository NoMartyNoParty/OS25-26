#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
	printf("Process' id: %d\n", getpid());
	printf("Parent's process id: %d\n", getppid());
	
	pid_t newProcess = fork();

	if(newProcess == -1){
		perror("Error");
		return 1;
	}

	if(newProcess == 0){
		printf("Child's newProcess: %d\n", newProcess);
		printf("Child's id: %d\n", getpid());
		printf("Child's parent id: %d\n", getppid());
	}
	else {
		printf("Parent's newProcess: %d\n", newProcess);
		printf("Parent's id: %d\n", getpid());
		printf("Parent's parent id: %d\n",getppid());
	}

	return 0;
}
