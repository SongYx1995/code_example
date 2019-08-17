
#include <sys/msg.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct MyMessage
{
    int id;
    string data;
};
int main()
{

    MyMessage a;
    MyMessage b;
    a.id = 1;
    a.data = "12345";
    int queueid = msgget(IPC_PRIVATE, IPC_CREAT | 0600);


    int rc = msgsnd(queueid, &a, a.data.size() + 4, 0);
    if (rc == -1)
    {
        cerr << ("error");
        exit(1);
    }
    rc = msgrcv(queueid, &b, 2, 0, 0);
    if (rc == -1)
    {
        cerr << ("msgrcv error");
        exit(1);
    }
    cout << b.data << endl;
}