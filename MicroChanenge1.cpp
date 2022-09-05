// 例子：一家工业公司有N家工厂，每个月都产生一些污染。公司已决定减少总烟尘 通过给一些工厂配备一个或多个过滤器来减少排放。
// 每一个这样的过滤器都会使工厂的污染减少一半。当安装第二个（或随后的过滤器）时，再一次将安装现有过滤器后排放的剩余污染物减少一半。
// 例如，一个最初产生6个单位污染物的工厂将 用一个过滤器生成3个单元1.5个单元两个单元0.75个单元三个单元。
// 给出一个由N个整数组成的数组来描述工厂产生的污染量。你的任务是找到过滤器的最低数量需要减少污染的总和至少一半写一个函数:
// class public int solution（int[] A){ }
// 给定一个长度为N的整数A数组，返回减少一半总污染所需的最小过滤器数量。
#include <queue>
using namespace std;
int solution(int A[])
{
    priority_queue<int> q;
    int n = sizeof(A) / sizeof(A[0]);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        q.push(A[i]);
        sum += A[i];
    }
    int reduce = 0;
    int cnt = 0;
    while (reduce * 2 < sum)
    {
        int curMax = q.top();
        q.pop();
        curMax /= 2.0;
        reduce += curMax;
        q.push(curMax);
        ++cnt;
    }
    return cnt;
}