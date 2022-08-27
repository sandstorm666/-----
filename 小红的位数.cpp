#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace  std;

int operation = 0;
bool isValid(string s1, string s2)
{
    int n1 = stoi(s1);
    int n2 = stoi(s2);
    if (!(n1 % n2) || !(n2 % n1))
        return true;
    return false;
}
//这种最少的数组题目一般用bfs，动态规划
// 注意dfs对状态的改变需要在递归后状态还原
/*bfs遍历，以后全排列的遍历找最少操作的问题，要先考虑bfs和dfs
先从4位数开始，然后在bfs的过程中慢慢变3位数，2位数，1位数
*/
int bfs(string s1, string s2)
{

    queue<string> v1;
    queue<string> v2;
    v1.push(s1);
    v2.push(s2);
    //先拿到所有可能的结果
    while (!v1.empty())
    {
        int size = v1.size();
        for (int i = 0;i < size;++i)
        {
            string t1 = v1.front();
            v1.pop();
            for (int j = 0;j < t1.size();++j)
            {
                string temp = t1;
                temp.erase(i, i + 1);
                if (!temp.empty())
                    v1.push(temp);
            }
        }
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 0 || b == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    string s1, s2;
    s1 = to_string(a);
    s2 = to_string(b);
    if (isValid(s1, s2))
    {
        cout << 0 << endl;
        return 0;
    }
    //从删除一位开始
    bfs(s1, s2);
    if (operation == 0)
        operation = -1;
    cout << operation << endl;
    return 0;
}