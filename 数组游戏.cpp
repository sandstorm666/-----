#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;


int getRes(vector<int>& nums, int k)
{
    int n = nums.size();
    nums.resize(nums.size() * 2);
    int cnt = 0;
    while (true) {
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                ++cnt;
                if (cnt == k) {
                    return nums[i - 1];
                }
                nums[i + n - 1] = nums[i];
                nums[i] = nums[i - 1];
            }
            else {
                cnt = 1;
                nums[i + n - 1] = nums[i - 1];
            }
        }
        memmove(&*nums.begin(), &*nums.begin() + n - 1, n);
    }
}



// 分割字符串
vector<string> splitString(const string& str, const string& delim)
{
    vector<string> res;
    auto start = str.cbegin();
    while (start < str.cend())
    {
        auto it = std::search(start, str.cend(), delim.cbegin(), delim.cend());
        res.emplace_back(start, it);
        start = it + delim.size();
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);

    auto input = splitString(str, " ");

    vector<int> nums;
    for (int i = 0; i < input.size() - 1; ++i) {
        nums.push_back(stoi(input[i]));
    }
    int k = stoi(input.back());

    // vector<int> nums = {2, 1, 4, 3, 6, 5, 0, 7};
    cout << getRes(nums, k) << endl;
    return 0;
}