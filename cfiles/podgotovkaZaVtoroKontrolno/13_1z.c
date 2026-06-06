#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
	printf("Process id: %d\n", getpid());
	printf("Parent's process id: %d\n", getppid());
	printf("Exec through 'ps'....\n");

	int result = execlp("ps", "ps", NULL);

	printf("Result of 'ps': %d\n", result);
	
	if(result == -1){
		perror("Error!");
		return 1;
	}

	return 0;
}
