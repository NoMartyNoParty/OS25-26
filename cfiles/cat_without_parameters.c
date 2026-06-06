#include <unistd.h>
#include <sys/types.h>

int main(){
	char buffer;
	ssize_t n_read;


	while((n_read = read(0, &buffer, sizeof(buffer))) > 0){
		if(write(1, &buffer, n_read) != n_read){
			return 1;
		}
	}
	return 0;
}
