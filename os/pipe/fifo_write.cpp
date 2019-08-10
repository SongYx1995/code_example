#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <signal.h>

int main()
{
    int fd = open("fifo", O_WRONLY);
    assert(fd != -1);
    char buff[128] = {0};
    while (1)
    {
        printf("input:\n");
        fgets(buff, 128, stdin);
        write(fd, buff, strlen(buff));
        if (strncmp(buff, "end", 3) == 0)
        {
            break;
        }
    }
    close(fd);
    exit(0);
}