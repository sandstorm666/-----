// 题目说可以重复打怪物过，但是如果能一遍过，必然不需要重复，能重复打怪过，则一定会一次过
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 抵达铁门时可能的最大生命值，如果不可达，则返回 -1。
     * @param cave int整型vector<vector<>> 洞穴的信息
     * @param hp int整型 小明的初始生命值
     * @return int整型
     */
    pair<int, int>directions[4] = { {0,-1},{0,1},{1,0},{-1,0} };
    int len = -1;
    void dfs(vector<vector<int>>& maze, int x, int y, int n, int m, vector<vector<int>>& visited, int life)
    {
        //出口为-3
        if (maze[x][y] == -3 && life > len)
        {
            len = life;
        }
        for (auto dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && maze[newX][newY] != -1)
            {
                visited[newX][newY] = 1;
                if (maze[newX][newY] > 0)
                    dfs(maze, newX, newY, n, m, visited, life - maze[newX][newY]);
                else
                    dfs(maze, newX, newY, n, m, visited, life);
                visited[newX][newY] = 0;
            }
        }
    }
    int EscapeFromCave(vector<vector<int> >& cave, int hp) {
        // write code here
        if (cave.empty() || cave[0].empty())
        {
            return -1;
        }
        int n = cave.size();
        int m = cave[0].size();
        //先找到起点
        pair<int, int> begin{ -1,-1 };
        for (int i = 0;i < n;++i)
        {
            for (int j = 0;j < m;++j)
            {
                if (cave[i][j] == -2)
                {
                    begin.first = i;
                    begin.second = j;
                    break;
                }
            }
            if (begin.first != -1)
                break;
        }
        vector<vector<int>> visited(n, vector<int>(m, 0));
        dfs(cave, begin.first, begin.second, n, m, visited, hp);
        return len;
    }
};