#include <unistd.h>
#include <iostream>
int main()
{
    int fd[2];
    pipe(fd);

    pid_t p = fork();
    if (p < 0)
    {
        std::cerr << "error" << std::endl;
    }
    else if (p > 0)
    {
        close(fd[0]);
        std::cout << "parent put 12" << std::endl;
        int *a = new int(12);
        write(fd[1], a, sizeof(int));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int *b = new int();
        read(fd[0], b, sizeof(int));
        std::cout << "child get " << *b << std::endl;
        close(fd[0]);
    }
}