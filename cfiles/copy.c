#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd1, fd2;
    ssize_t n_read;
    char buffer;

    if (argc != 3) {
        printf("Употреба: %s файл1 файл2\n", argv);
        return 1;
    }

    fd1 = open(argv[2], O_RDONLY);
    if (fd1 == -1) {
        perror("Грешка при отваряне на изходния файл");
        return 2;
    }

    fd2 = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1) {
        perror("Грешка при създаване на целевия файл");
        close(fd1);
        return 3;
    }

    while ((n_read = read(fd1, buffer, sizeof(buffer))) > 0) {
    	    if (write(fd2, buffer, n_read) != n_read) {
            perror("Грешка при запис");
            close(fd1);
            close(fd2);
            return 4;
        }
    }

    close(fd1);
    close(fd2);

    return 0;
}

