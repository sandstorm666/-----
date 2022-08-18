#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N = 1e5;
int id;
map<string, int> gname; //公司name
map<string, int> pname; //人name
map<int, int> mp;       // 存放当前查询时，该人关注的公司数量
int fa[N], cur[N];      // fa记录父节点，cur记录父节点相同的节点个数
//寻找父节点
int getfa(int u)
{
    return fa[u] != u ? getfa(fa[u]) : u;
}
//将v的父节点改为u
void join(int u, int v)
{
    int f1 = getfa(u), f2 = getfa(v);
    if (f1 != f2)
    {
        fa[f2] = f1;
        cur[f1] += cur[f2];
        cur[f2] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); //解除cin与cout的绑定，因为每次执行<<，都会调用flush，增加io负担
    cout.tie(0);

    int n;
    cin >> n;
    id = n;
    string p, g;
    int cmd;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cmd;
        if (cmd == 1) //插入
        {
            int m;
            cin >> p >> m;
            int root = i;
            pname[p] = root; //记录人的节点
            fa[root] = root;
            cur[root] = 0;
            for (int j = 0; j < m; ++j)
            {
                cin >> g;
                if (gname.find(g) == gname.end()) //如果不存在
                {
                    gname[g] = ++id;
                    fa[gname[g]] = gname[g];
                    cur[gname[g]] = 1;
                }
                join(root, gname[g]);
            }
            mp[root] = m;
        }
        else //查询
        {
            cin >> p;
            if (pname.find(p) == pname.end())
            {
                cout << "error\n";
                continue;
            }
            int pid = pname[p];
            int total = cur[getfa(pid)];
            int query = mp[pid];
            cout << total - query << "\n";
        }
    }
}