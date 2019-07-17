### 进程和线程以及区别
#### 进程
1. 进程是程序在一个数据集合上运行的过程，是系统进行资源分配和调度运行的一个独立单位。
2. 进程定义为程序的一次执行，由“程序+数据+进程控制快”构成
3. 进程两个特性，动态性，并发性
4. 进程的两个基本属性：１。进程是一个可拥有资源的独立单位２，进程同时又是一个可独立调度和分派的基本单位
5. 如果说：在操作系统中引入进程的目的，是为了使多个程序能并发执行，以提高资源的利用率和系统的吞吐量，那么在操作系统中再引入线程，则是为了减少程序在并发执行时所付出的时空开销，使ＯＳ具有更好的并发性
#### 线程
1. 线程，是进程的子任务，是可独立调度和分配的基本单位
2. 进程在执行过程中拥有独立的内存单元，而多个线程共享进程的内存

#### 区别总结
对于有线程系统：
* 进程是资源分配的独立单位
* 线程是资源调度的独立单位
对于无线程系统：
* 进程是资源调度、分配的独立单位

### 进程间的通信的几种方式
* 管道（PIPE）
    
    * 有名管道（named pipe，FIFO）：一种半双工的通信方式，它允许无亲缘关系进程间的通信
        * 优点：可以实现任意关系的进程间的通信
        * 缺点：
            1. 长期存于系统中，使用不当容易出错
            2. 缓冲区有限
    * 无名管道（unnamed pipe)：一种半双工的通信方式，只能在具有亲缘关系的进程间使用（父子进程）
        * 优点：简单方便
        * 缺点：
            1. 局限于单向通信 
            2. 只能创建在它的进程以及其有亲缘关系的进程之间
            3. 缓冲区有限

    管道是一个固定大小的缓冲区。在Linux中，该缓冲区的大小为1页，即4K字节

<details>
<summary>无名管道例子</summary>

```cpp
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
```

```cpp
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
```
</details>

<details>
<summary>有名管道例子</summary>
管道文件仅仅是文件系统中的标示，并不在磁盘上占据空间。在使用时，在内存上开辟空间，作为两个进程数据交互的通道。

首先通过命令创建管道文件：fifo

```bash
mkfifo fifo
```
写进程
```cpp
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
```
读进程
```cpp
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
```
</details>
