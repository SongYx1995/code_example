#include <unistd.h>
#include <stdio.h>
int main()
{
    int fd[2];
    pipe(fd);

    write(fd[1], "hello world", 12);
    // sleep(0);
    char buff[128];
    int n = read(fd[0], buff, 127);
    close(fd[0]);
    close(fd[1]);
    printf("read:%s\n", buff);
}