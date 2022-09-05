#include <iostream>
#include <vector>
using namespace std;
/*第三次手写堆排序
heapify时要注意终点自己传入的是尺寸还是下标，循环时下标不能超过尺寸的
还有heapify时，循环内要注意及时退出，不要忘了break分支
*/
void heapify(vector<int> &v, int begin, int end) // begin是索引，end都是长度，begin不可能=end
{
    while (begin < end)
    {
        int leftchild = 2 * begin + 1; // 这里是下标
        int rightchild = 2 * begin + 2;
        int cur = begin;
        if (leftchild < end && v[leftchild] > v[cur])
        {
            cur = leftchild;
        }
        if (rightchild < end && v[rightchild] > v[cur])
        {
            cur = rightchild;
        }
        if (cur != begin)
        {
            swap(v[begin], v[cur]); //节点值取3个关联节点中的最大值
            begin = cur;
        }
        else //别忘了退出条件
            break;
    }
}
void buildHeap(vector<int> &v, int length)
{
    for (int i = (length >> 1) - 1; i >= 0; --i) // 从最后一个拥有子节点父节点开始
    {
        heapify(v, i, length); // length是长度
    }
}
void heapSort(vector<int> &v)
{
    int n = v.size();
    // 先构建大根堆然后将最大值移动到数组末尾
    buildHeap(v, n);
    // 最后数组就是从小到大排列的了
    for (int i = n; i > 0; --i)
    {
        swap(v[0], v[i - 1]);
        heapify(v, 0, i - 1);
    }
    for (auto x : v)
    {
        cout << x << ",";
    }
}
int main()
{
    vector<int> v{2, 2, 5, 3, 6, 9, 7, 8, 4, 2, 1, 10};
    heapSort(v);
}