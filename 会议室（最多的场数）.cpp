#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 一些项目要占用一个会议室宣讲，会议室不能同时容纳两个项目的宣讲。
// 给你每一个项目开始的时间和结束的时间(给你一个数 组，里面是一个个具体 的项目)，你来安排宣讲的日程，
// 要求会议室进行的宣讲的场次最多。 返回这个最多的宣讲场次。
bool cmp(pair<int, int> &a, pair<int, int> &b) //优先按照终点排序
{
    if (a.second == b.second)
        return a.first < b.first;
    // 当end相等时,按照start升序,例如:[1,2] [2,2] 是可以算两天的
    return a.second < b.second;
}
// 排序即可解决
int main(void)
{
    int n, start, end, result = 0;
    scanf("%d", &n);
    vector<pair<int, int>> conference; // first:start,second:end

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &start, &end);
        conference.push_back(make_pair(start, end));
    }

    sort(conference.begin(), conference.end(), cmp);

    start = conference[0].first;
    for (int i = 0; i < n; i++)
    {
        if (start <= conference[i].first)
        {
            result++;
            start = conference[i].second;
        }
        // cout << conference[i].first << "  " << conference[i].second << endl;
    }

    cout << result;

    return 0;
}