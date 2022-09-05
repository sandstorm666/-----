#include<iostream>
#include<vector>
using namespace std;
/*寻找三元组
先找到两个相同的元素值，再判断这两个元素中间有没有值
*/
//输出三元组的数量
//优化地方在于如何快速找到重复的数
// 可以先初始化一个数组vec，如果有对应的数字出现，则记录，在数组vec内记录对应的下标。
// 比如输入103的数字，则vec[103]记录对应的103出现的下标
int cnt = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    while (n--)
    {
        int ele;
        cin >> ele;
        vec.emplace_back(ele);
    }
    //先寻找拥有相同元素的下标
    for (int i = 0;i < vec.size();++i)
    {
        for (int j = 1; j < vec.size(); ++j)
        {
            if (vec[i] == vec[j] && (j - i) > 1)//间隔必须＞1
            {
                for (int k = i + 1; k < j; ++k)
                {
                    if (vec[i] > vec[k])
                        cnt++;
                }

            }
        }

    }
    cout << cnt << endl;
}