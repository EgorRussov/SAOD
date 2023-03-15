#include <iostream>
#include "Strh.h"
using namespace std;
void Test(Str s) {
  
}
int main()
{
    Str s = "123";
    cout << s << " " << strlen(s)<< endl;
    Test(s);
    cout << s << " " << strlen(s)<< endl;
    Str t;
    t = s;
    t += " 123";
    cout << t<< endl;
    Str a = s + " " + "abc";
    cout << a;
}
