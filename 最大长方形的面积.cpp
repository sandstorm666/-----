#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
// 4,1,2,7
// 将字符串分割为数组
// 搞错了，应该采用接雨水的双指针方法。
int main()
{
    vector<int>heights;
    int value;
    string str;
    getline(cin, str);
    str.erase(0, 1);
    str.erase(str.size() - 1, str.size());
    int pos = 0;
    while ((pos = str.find(',')) != str.npos)
    {
        value = stoi(str.substr(0, pos));
        heights.push_back(value);
        str.erase(0, pos + 1);
    }
    value = stoi(str.substr(0, str.size()));
    heights.push_back(value);

//单调栈

    int n = heights.size();
    vector<int> left(n), right(n, n);

    stack<int> stk;
    for (int i = 0; i < n; ++i)
    {
        while (!stk.empty() && heights[stk.top()] >= heights[i])
        {
            right[stk.top()] = i;
            stk.pop();
        }
        left[i] = (stk.empty() ? -1 : stk.top());
        stk.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    cout << ans << endl;
}