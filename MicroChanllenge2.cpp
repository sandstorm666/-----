/*
译文（仅供参考）：挑战3描述 患者需要在接下来的N天内康复（从0到N-1）。康复包括X次治疗。
为每一个康复疗程，与上一次不同，下一次疗程正好在Y天之后。给你一个N个整数数组A，列出了N天内每个康复疗程的费用：
也就是说，第K天的康复费用A【K】。
写一个函数: {public int solution（int[] a,int x,int y）；}
给定数组A和两个整数X和Y返回重建的最小成本 这是保证，它总是有可能完成所有x康复会议。
例子：
1.给定A=[4,2,3,7], X=2 and Y=2,，你的函数应该返回7，这是在第0天和第2天（7=4+3）的成本之和
2.假设A= [10,3,4,7], X=2 and Y=3，你的函数应该会返回17，因为只有在第0天和第3天才有可能康复
*/
#include <vector>
using namespace std;
/* 思路：
在给定数组中取X个数字，满足数字间间隔为Y-1，求最小和。数组长度最大1e5。
看成Y个一行的矩阵，在每一列上用滑动窗口求长度为X的子数组的最小和。
注意正好是Y天所以是在每一列上求。
*/
int solution(vector<int> &A, int X, int Y)
{
    // write your code in C++ (C++14 (g++ 6.2.0))
    int N = A.size();
    int rcnt = N / Y + (int)(N % Y > 0);

    auto rc2A = [&](int r, int c)
    { return r * Y + c; };

    int res = INT_MAX;
    for (int c = 0; c < Y; c++)
    {
        int cur = 0;
        int h = 0, t = 0;
        while (t < rcnt)
        {
            if (rc2A(t, c) > N - 1)
                break;
            cur += A[rc2A(t, c)];
            t++;
            while (t - h > X)
                cur -= A[rc2A(h, c)], h++;
            // cout << cur << ' ' << c << ' ' << h << ' ' << t << endl;
            if (t - h == X)
                res = min(cur, res);
        }
    }
    return res;
}