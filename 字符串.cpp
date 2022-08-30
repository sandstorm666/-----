#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a{"abcdefg"};
    int x = a.find("fg", 2);
    cout << "x= " << x << endl;
}