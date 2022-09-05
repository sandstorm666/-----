#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 病毒入侵其实就是找最少的重叠区间数，不要被题目绕晕了
// 学会从复杂的题干中提炼出核心需求
int main()
{
    int v;
    cin >> v;//伪装度
    int n;
    cin >> n;//设备数
    int x;
    cin >> x;//容忍度
    vector<int>a;
    while (n--)
    {
        int ai;
        cin >> ai;
        a.emplace_back(ai);
    }
    //寻找最小重叠区间
    int minVal = a[0];
    int maxVal = a[0];
    int count = 0;
    for (auto& v : a)
    {
        if (v < minVal)
            minVal = v;
        else if (v > maxVal)
            maxVal = v;
        if (maxVal - minVal >= 2 * x)
        {
            minVal = 0;
            maxVal = 0;
            count++;
        }
    }
    return count;
}