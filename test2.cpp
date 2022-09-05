#include<iostream>
using namespace std;
class T
{
    static int count;
public:
    T(int i = 0)
    {
        count++;
        cout << "#";
    }
    T(T& p)
    {
        count++, cout << "&";
    }
    ~T()
    {
        count--;
        cout << count << "*";
    }
};
int T::count = 0;
int main()
{
    T* p = new T[5];
    delete[]p;
    p = new T;
    T* q = new T(*p);
    delete p;
    delete q;
    return 0;
}