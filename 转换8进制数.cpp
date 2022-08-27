#include<stack>
using namespace std;
void conv(int a, char* out, size_t out_len)
{
    stack<int> s;
    while (a)
    {
        s.push(a % 8);
        a /= 8;
    }
    int i = 0;
    while (!s.empty())
    {
        out[i] = s.top();
        s.pop();
    }
    out_len = i;
}
int func(int a)
{
    while (a)
    {
        if (a % 2 != 0)//不是偶数
        {
            return 0;
        }
        else if (a == 2)
            return 1;
        a /= 2;
    }
    return 0;
}
char* strndup(char* src, int n)
{
    char* dst = (char*)malloc(n * 1);
    memset(dst, 0, n);//初始化
    for (int i = 0;i < n;++i)
    {
        dst[i] = src[i];
    }
    return dst;
}


typedef struct link_t
{
    int val;
    link_t* next;
};
link_t* merge(link_t* lnk1, link_t* lnk2)
{
    link_t* preHead = new link_t{ -1 };

    link_t* prev = preHead;
    while (lnk1 != nullptr && lnk2 != nullptr)
    {
        if (lnk1->val < lnk2->val)
        {
            prev->next = lnk1;
            lnk1 = lnk1->next;
        }
        else if (lnk1->val < lnk2->val)
        {
            lnk1 = lnk1->next;
        }
        else
        {
            prev->next = lnk2;
            lnk2 = lnk2->next;
        }
        prev = prev->next;
    }

    // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
    prev->next = lnk1 == nullptr ? lnk2 : lnk1;

    return preHead->next;
}

void reverse(char* s)
{

    stack<char> stk;
    int i = 0;
    while (s[i] != '\0')
    {
        stk.push(s[i++]);
    }
    i = 0;
    while (!stk.empty())
    {
        s[i++] = stk.top();
        stk.pop();
    }
}
unsigned int count(unsigned char* buffer, size_t len)
{
    unsigned int cnt = 0;
    int n = len / sizeof(unsigned char);
    for (int i = 0;i < n;++i)
    {
        unsigende char ch = buffer[i];
        while (int j = 0;j < sizeof(unsigned char);++j)
        {
            if (ch & 0x01)
            {
                cnt++;
            }
            ch >> 1;
        }
    }
    return cnt;
}

