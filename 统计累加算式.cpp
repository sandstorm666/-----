#include <iostream>
#include <vector>
using namespace std;
// 不是动态规划！！！
// 是由规律的
// 奇数：有f(n-1)种结果
// 偶数：有f(n-1)+f(n/2)种结果
int main()
{
    int n;
    cin >> n;
    vector<int> dp(1001, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (i & 1)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i / 2];
        }
    }
    cout << dp[n] << endl;
    return 0;
}