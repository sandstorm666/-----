// 小明的服务器遭到了黑客的攻击，他想了一个简易的办法来判断服务器收到的数据包是否是来自黑客的攻击。
// 小明假设黑客的攻击都是往一些模式串里插入一个片段伪装出来的，例如模式串M为AN-- ATTACK，那么黑客可能往M里插入一段信息，
// 如在AN - 后插入hello，来得到伪装后的数据包，AN - hello - ATTACK。小明想出了一系列的模式串Mi，
// 你能否帮助小明判断服务器收到的数据包是否可能由某个模式串伪装而成。
// 示例，给定两个模式串M1 = abc，M2 = abd，那么数据包abec可能是攻击（模式M1），但数据包xyz则不属于M1、M2里面任何一个类型的攻击。
// 输入的第一行一个正整数n（1 ≤ n ≤ 100000），表示n种攻击模式。
// 接下来n行，其中第i行一个字符串Mi（1 ≤ strlen(Mi) ≤ 50），表示第i种攻击模式。
// 在接下来一个正整数k，表示有k（1 ≤ k ≤ 100）个数据包。
// 接下来k行，其中第i行一个字符串Di（1 ≤ strlen(Di) ≤ 1000），表示第i个数据包。
// 有50%的输入数据满足：1 ≤ n ≤ 10
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;
set<int> len;                  // 存黑客的代码段长度
unordered_map<string, int> mp; // key是代码串，value是1
void insert(string &s)
{
    mp[s] = 1;
}
void process(string &s)
{
    for (auto length : len)
    {
        if (s.size() < length)
            break;
        // 检测代码段是否有黑客代码段填充而来，比如黑客代码段位abc，测试代码段为 axxbc或者abxxc，均是yes
        for (int i = 0; i <= length; i++)
        {
            string tm;
            int l = i, r = length - i, siz = s.size();
            if (l)
                tm += s.substr(0, l);
            if (r)
                tm += s.substr(siz - r); // size - length + i;测试长度-黑客代码段长度+i
            if (mp[tm])
            {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }
}
int main()
{
    int n, m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        len.insert(s.size());
        insert(s);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        process(s);
    }
    return 0;
}