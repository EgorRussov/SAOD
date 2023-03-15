#include <iostream>
#include "Test.h"
using namespace std;

int Test::nCount = 0;
//Test t1;
void foo(Test t) {
    cout << "foo is running" << endl;
}
int main()
{
    /*{
        cout << "Before creating object" << endl;
        Test t;
        foo(t);
        cout << "After creating object" << endl;
        cout << endl;
        cout << "Before deleting object" << endl;
    }
    cout << "After deleting object" << endl;
    Test* p = new Test;
    delete p;
    Test* arr = new Test[5];
    delete[] arr;*/
    //Child c;
    //Aggregate a;
    AggregateT<Test> aggrTest;
    AggregateT<Child> aggrChild;
}

