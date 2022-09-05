#include<iostream>
using namespace std;

int fun(int* ptr, int val)
{
    *ptr = 1;
    val = 1;
    return *ptr + val;
}
void caller(int val)
{
    int ptr = 2;
    int ret;
    val = 3;
    ret = fun(&ptr, val);
    printf("%d,%d,%d\n", ptr, val, ret);
}
int main()
{
    int a = 9876;
    int b = 9867;
    if (!(b / a))
    {
        cout << 1;
    }
    if (!a || !b)
    {
        cout << 2;
    }
    if (a && b)
    {
        cout << 3;
    }
    if (!!(b / a * 1.0))
    {
        cout << 4;
    }
    char ch[] = "abc\0def", * p = ch;
    printf("%c\n", *p + 4);
    unsigned short int i = (unsigned short int)(-1234);
    printf("%hu\n", i);
    a = 5;b = 6;int w = 1, x = 2, y = 3, z = 4;
    (a = w > x) && (b = y > z);
    cout << a << " , " << b << endl;
    caller(3);
}