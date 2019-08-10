#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>

int main()
{
    int fd = open("fifo", O_RDONLY);
    assert(fd != -1);
    char buff[128] = {0};
    int n = 0;
    while ((n = read(fd, buff, 127)) > 0)
    {
        printf("read:(n = %d)%s\n", n, buff);
        //将buff中的数据清空e
        memset(buff, 0, 128);
    }
    close(fd);
    exit(0);
}