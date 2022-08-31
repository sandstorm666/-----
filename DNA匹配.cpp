#include<string>
#include<iostream>
using namespace std;
int cnt = 0;
void func(string& a, string& b)
{
    int n = a.length();
    int ai = 0, bi = 0;
    for (int i = 0;i < n;++i)
    {
        if (a[i] != b[i] && a[i] == 'A')
        {
            ai++;
        }
        if (a[i] != b[i] && a[i] == 'T')
        {
            bi++;
        }
    }
    //cout << "x=" << x << endl;
    int  m = min(ai, bi);
    int res = max(ai, bi) - m;
    cnt = m + res;
}
int main()
{
    string a, b;
    cin >> a >> b;
    if (a == b)
        cout << 0;
    func(a, b);
    cout << cnt << endl;
    return 0;
}