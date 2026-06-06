#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	printf("The id of the process: %d", getpid());

	printf("\nThe id of the parent process: %d", getppid());

	pid_t result = fork();

	if( result == -1){
		perror("Error!");
		return 1;
	}

	if( result == 0){
		printf("\nThis process is executed only by the descendant");
	}
	else{
		printf("\nThis process is executed only by the parent");
	}

	printf("\nResult of fork(): %d", result);
	printf("\nCurrent id: %d", getpid());
	printf("\nCurrent parent's id: %d", getppid());

	return 0;
}
