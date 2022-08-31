#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算dag 路径上起始到目的节点的路径数目
     * @param nodes int整型vector<vector<>> 第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ），若为空，就是没有下一个节点了。
     * @return int整型
     */
    int ans = 0;
    void dfs(int id, map<int, vector<int>>& mp)
    {
        if (id == 4)
        {
            ans++;
            return;
        }
        if (mp[id].empty())
            return;
        for (auto& node : mp[id])
        {
            dfs(node, mp);
        }
    }
    // 计算0-4共有多少条路可以走
    int DagPathNum(vector<vector<int> >& nodes) {
        map<int, vector<int>> mp;//构建图结构
        for (int i = 0;i < nodes.size();++i)
        {
            mp[i] = nodes[i];
        }
        dfs(0, mp);
        return ans;

    }
};