#include <iostream>
#include <vector>
typedef long long ll;
const int N = 1e5;
using namespace std;
vector<vector<int>> mp(N);
string color;
ll ans;
int cred[N], cblue[N], n;
void dfs(int u, int fa)
{
    cred[u] = cred[fa];
    cblue[u] = cblue[fa];
    if (color[u] == 'R')
        cred[u]++;
    else
        cblue[u]++;
    ans += abs(cred[u] - cblue[u]);
    for (auto v : mp[u])
    {
        if (v == fa) //代表路径已走过
            continue;
        dfs(v, u);
    }
    return;
}
int main()
{
    cin >> n >> color;
    color = " " + color;
    for (int i = 0, u, v; i < n - 1; ++i)
    {
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
}
