#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int i;
    list<int> ilist;
    cout << "size=" << ilist.size() << endl;
    ilist.push_back(0);
    ilist.push_back(1);
    ilist.push_back(2);
    ilist.push_back(3);
    cout << "size=" << ilist.size() << endl;

    list<int>::iterator ite;
    for (ite = ilist.begin(); ite != ilist.end(); ite++)
        cout << *ite;
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 2);
    cout << *ite;
    cout << endl;

    cout << *(ilist.insert(ite, 99));
    cout << endl;

    for (ite = ilist.begin(); ite != ilist.end(); ite++)
        cout << *ite;
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 1);
    cout << *(ilist.erase(ite));
}
