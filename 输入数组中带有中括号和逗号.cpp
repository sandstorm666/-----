#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
//灵活使用strtok函数！！！
int main()
{
    vector<vector<int>> arr;
    string input;
    char *tok;
    while (getline(cin, input))
    {
        if (input.size() > 0)
        {
            vector<int> a;
            //第一次调用，函数会对字符串进行分割，分割的delim也可以是个字符串，delim的每个字符都会生效
            //源字符串中delim字符会被变为\0
            tok = strtok((char *)input.c_str(), " ,[]");
            while (tok != NULL)
            {
                a.push_back(stoi(tok));
                //在进行第一次调用结束时，会记录下被修改成字符  '\0'位置的字符的地址。在第二次进行函数调用时，函数的第一个实参为NULL，
                //这里函数会直接从上一次记录的字符的地址的后一个位置开始进行比对，看是不是还有和源字符串相同的字符，如果有，那就将它修改为 字符0，并返回刚才开始比对的字符的地址。
                tok = strtok(NULL, " ,[]");
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