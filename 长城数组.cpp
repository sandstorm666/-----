#include<iostream>
#include<vector>
using namespace std;
int oper = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    while (n--)
    {
        int a;
        cin >> a;
        vec.emplace_back(a);
    }
    //先选的位置形成的长城三元组会对后面的产生影响
    int cnt = 0;
    for (int i = 0;i < vec.size();++i)
    {
        for (int j = i + 2;j < vec.size();++j)
        {

        }
    }
    cout << oper << endl;
}