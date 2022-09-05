#include <iostream>
using namespace std;
int main()
{
    int a[2][3]{1, 2, 3, 4, 5, 6}; //不在堆区，栈区多维数组是连续的
    int *p = *a;
    cout << "p = " << *(p + 5) << endl;
}