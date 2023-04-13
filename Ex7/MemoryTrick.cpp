#include <iostream>
#include <vector>
#include "Test.h"

using namespace std;

shared_ptr<Test> foo() {
    shared_ptr<Test> ptr(new Test());
    ptr->Val = 10; 
    return ptr;
}

Test* goo() {
    Test* ptr = new Test();
    ptr->Val = 10;
    return ptr;
}

int main()
{
    vector<int> v;
    int a = v.capacity();
    for (int i = 0; i < 32; i++) {
        v.push_back(1);
        int b = v.capacity();
        if (b != a) {
            cout << v.size() << " " << v.capacity() << endl;
            a = v.capacity();
        }
    }
    shared_ptr<Test> t;
    {
        auto p = foo();
        t = p;
        cout << p->Val << endl;
    } 
    cout << "after block" << endl;
    auto g = goo();
    cout << "Val = " << g->Val << endl;
    delete g;
}
