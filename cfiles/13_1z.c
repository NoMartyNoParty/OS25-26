#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
	printf("The id of the process:%d", getpid());
	
	printf("\nThe id of the parent process:%d", getppid());

	printf("\nConverting with 'ps'...");

	int result = execlp("ps", "ps", NULL);

	if(result == -1){
		perror("Error");
		return 1;
	}
	
	return 0;
}
