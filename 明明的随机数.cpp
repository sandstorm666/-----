#include <iostream>
#include <vector>
using namespace std;
// 明明生成了NN个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，
// 然后再把这些数从小到大排序，按照排好的顺序输出。
// 数据范围： 1 <= n <= 1000  ，输入的数字大小满足 1 <=val <=500.

/*使用数组下标记录数有没有出现，即使重复出现了，下标还是只有一个，并且还是按照顺序排列的*/
int a[501];
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        a[n] = 1;
    }
    for (int i = 0; i <= 500; ++i)
    {
        if (a[i] == 1)
            cout << i << endl; //注意是下标代表的输入的元素值
    }
    return 0;
}