#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    vector<vector<int>> arr;
    string input;
    while (getline(cin, input))
    {
        if (input.size() > 0)
        {
            stringstream stringin(input);
            int num;
            vector<int> a;
            while (stringin >> num)
            {
                a.push_back(num);
            }
            arr.push_back(a);
        }
    }
    // 使用自测数据按钮时调试用，正式提交时要删掉。
    cout << "rows: " << arr.size() << ", cols: " << arr[0].size() << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}