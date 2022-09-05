#include<iostream>
using namespace std;
class A
{
public:
    int a;
    virtual void testa() {}
    void print();
    static int b;
};
int A::b = 0;//声明的时候加，定义的时候不需要加static
/*类里面如果有虚函数，则sizeof(A)会比普通的类的多一个虚表的指针，静态变量对类的sizeof没有影响*/
int main()
{
    A a1;
    a1.a = 1;
    cout << "sizeof=" << sizeof(a1) << endl;
    return 0;
}