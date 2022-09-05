#include <iostream>
#include <cstdio>
using namespace std;
// 陈老师是一个比赛队的主教练，有一天，他想给团队成员开会，应该为这次会议安排教室，但教室缺乏，
// 所以教室管理员必须通过接受订单和拒绝订单优化教室的利用率。 如果接受一个订单，则该订单的开始时间和结束时间成为一个活动。
// 注意，每个时间段只 能安排一个订单。请找出一个最大化的总活动时间的方法。你的任务是这样的：
// 读入订单， 计算所有活动（接受的订单）占用时间的最大值。
#define MAX 20 //仅说明方法，未按照题目要求
int n;
int ans, temp, counter;
// 使用dfs
struct classroom
{
    int start;
    int end;
};

void dfs(classroom a[], int i)
{
    counter = 0;
    for (int j = 1; j <= n; j++)
    {
        if (a[j].start >= a[i].end)
        {
            int t = (a[j].end - a[j].start);
            // 这里temp是全局变量，在递归中，递归的运算思路是先按一条路走到底，然后回退看有没有其余的分支，走向其余分支
            // 只要及时恢复状态，temp值就不会乱变
            temp += t;
            dfs(a, j);
            temp -= t; //状态恢复
            counter++;
        }
    }
    // counter==0代表，没有temp没有更新，这时统计temp是否是最大值
    if (counter == 0)
        if (temp > ans)
            ans = temp;
}

int main()
{
    cin >> n;
    classroom a[MAX];
    a[0].end = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i].start >> a[i].end;
    dfs(a, 0);
    cout << ans << endl;
    return 0;
}
/*
方法2：使用dp，双重循环，内存循环找出到当前时刻的最大使用时间，并赋值给dp，外层循环，将时刻往后推进。
是一维的dp。
*/