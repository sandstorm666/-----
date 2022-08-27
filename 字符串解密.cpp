#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//每个字符加上的魔法数字acsll码是一样的
bool Vaild(int num)
{
    if ((num >= 65 && num <= 90) || num == 32)
        return true;
    else
        return false;
}
//返回方法数量
int decode(vector<int>& v, int& x)
{
    //求解出最大值，最小值,倒数第二小的值
    //如果有两个小于65的且不一样的值，则无解
    vector<int> sortV(v);
    sort(sortV.begin(), sortV.end());
    int size = sortV.size();
    int maxVal = sortV[size - 1];
    int minVal = sortV[0];
    int cnt = 0; //方法数
    int midVal = 0;
    if (size > 2)
        midVal = sortV[1]; //倒数第二小的数
    if (size == 1 && Vaild(v[0]))
    {
        x = minVal - 65;
        cnt += x + 1;
        return cnt;
    }
    else if (size == 2)
    {
        x = minVal - 32;
        bool f = Vaild(maxVal - x);
        if (f) //空格只有一种解法
            cnt++;
        if (minVal >= 65 && maxVal <= 90)
        {
            x = minVal - 65;
            cnt += x + 1;
        }
        return cnt;
    }
    //从空格判断,如果有空格只有一种解法或者无解
    //如果没有空格，则可能有多种解法。
    if (minVal == midVal && midVal == maxVal)
    {
        if (minVal < 65)
        {
            cnt++;
            x = minVal - 32;
        }
        else if (minVal >= 65)
        {
            cnt += minVal - 65 + 2; //+2，包括都是空格
        }
        return cnt;
    }
    //3个都直接是合法字符,且没有空格
    if (Vaild(minVal) && Vaild(midVal) && Vaild(maxVal))
    {
        int x1 = minVal - 32;
        //是空格
        if (Vaild(midVal - x1) && Vaild(maxVal - x1))
        {
            x = x1;
            cnt++;
        }
        else if (minVal >= 65)
        {
            x = minVal - 65;
            cnt += x + 1;
        }
        return cnt;
    }
    // 只有最大值超了90
    //else if (Vaild(minVal) && Vaild(midVal))
    else
    {
        int x1 = minVal - 32;
        //有空格，一种或无解
        if (Vaild(midVal - x1) && Vaild(maxVal - x1))
        {
            x = x1;
            cnt++;
        }
        //没有空格,最小值大于65，最大值超过90
        //max和min之间的差不能超过25
        else if (minVal >= 65)
        {
            int x1 = minVal - 65;
            int x2 = maxVal - 90;
            if (x1 >= x2)
            {
                int x = x1 - x2;
                cnt += x + 1;
            }
        }
        return cnt;
    }
    return 0;
}

int main()
{
    int length;
    cin >> length;
    vector<int> v;
    while (length--)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    int x = 0;
    int num = decode(v, x);
    string s;
    if (num == 1)
    {
        for (auto n : v)
        {
            s.append(string{ char(n - x) });
        }
        cout << s << endl;
    }
}
// 15
// 82 79 86 86 89 42 97 89 92 86 78 42 100 100 100