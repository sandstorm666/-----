#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// 哈希表去重
int Func(vector<int>& nums)
{
    unordered_set<int> num_set;
    for (const int& num : nums)
    {
        num_set.insert(num);
    }

    int ans = 0;

    for (const int& num : num_set)
    {
        if (!num_set.count(num - 1))
        {
            int currentNum = num;
            int currentSum = 1;
            while (num_set.count(currentNum + 1))
            {
                currentNum += 1;
                currentSum += 1;
            }

            ans = max(ans, currentSum);
        }
    }

    return ans;
}

int main()
{
    int n = 0;
    cin >> n;
    std::vector<int> vec;
    for (int i = 0; i < n; ++i)
    {
        int nn = 0;
        cin >> nn;
        vec.push_back(nn);
    }

    int res = Func(vec);
    std::cout << res << std::endl;
    return 0;
}