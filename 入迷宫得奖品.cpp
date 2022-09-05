
struct Point {
    int x;
    int y;
    Point(int xx, int yy) : x(xx), y(yy) {}
};

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param maze int整型vector<vector<>> 迷宫数据 固定为4x4的二维数组，0表示路，可走；1 表示墙，不可通过； 8 表示礼物，是我们的目标
     * @return Point类vector
     */
    //入口可能不止一个，需要循环调用
    pair<int, int>directions[4] = { {0,-1},{0,1},{1,0},{-1,0} };
    int len = 17;
    vector<Point> ans;
    void dfs(vector<vector<int>>& maze, int x, int y, int m, int n, vector<vector<int>>& visited, int curL, vector<Point>& path)
    {
        //财报的地点不为1不为0
        if (maze[x][y] == 8 && curL < len)
        {
            len = curL;
            ans = path;
        }
        for (auto dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY] && maze[newX][newY] != 1)
            {
                visited[newX][newY] = 1;
                path.push_back(Point{ newX,newY });
                dfs(maze, newX, newY, m, n, visited, curL + 1, path);
                path.pop_back();
                visited[newX][newY] = 0;
            }
        }
    }
    vector<Point> winMazeGift(vector<vector<int> >& maze) {
        vector<Point> begin;
        if (maze.empty() || maze[0].empty())
            return {};
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        //从四个方向寻找入口
        for (int i = 0;i < n;++i)
        {
            if (maze[0][i] == 0)
                begin.push_back(Point{ 0,i });
        }
        for (int i = 1;i < m;++i)
        {
            if (maze[i][n - 1] == 0)
                begin.push_back(Point{ i,n - 1 });
        }
        for (int i = 0;i < n - 1;++i)
        {
            if (maze[m - 1][i] == 0)
                begin.push_back(Point{ m - 1,i });
        }
        for (int i = 1;i < m - 1;++i)
        {
            if (maze[i][0] == 0)
                begin.push_back(Point{ i,0 });
        }
        for (auto& pos : begin)
        {
            vector<vector<int>> visited(m, vector<int>(n, 0));
            visited[pos.x][pos.y] = 1;
            vector<Point> path{ Point{pos.x,pos.y} };
            dfs(maze, pos.x, pos.y, m, n, visited, 1, path);
        }
        return ans;
    }
};