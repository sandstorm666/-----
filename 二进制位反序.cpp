// 编写函数reverse，将val(32位无符号整数) 的二进制位反序。比如，如果val的二进制表示为1011000011111111，
// 反序后val的二进制表示为1111111100001101。
#include <stdio.h>
#include <string.h>
unsigned int reverse(unsigned int num)
{
    int a[32] = {0};
    int pos = 31;
    // 十进制转二进制
    while (num > 0)
    {
        a[pos] = num % 2;
        num /= 2;
        pos--;
    }
    num = 0;
    int p = 1;
    // 二进制转十进制
    // 需要用一个数记录一下是2的多少次方，只用num不行
    for (int i = 0; i < 32; ++i)
    {
        num += a[i] * p;
        p *= 2;
    }
    return num;
}

int main(int argc, char *argv[])
{
    unsigned int num = 0;
    unsigned int ret = 0;

    if (1 != fscanf(stdin, "0x%x", &num))
    {
        fprintf(stderr, "input error\n");
        return 0;
    }
    ret = reverse(num);
    printf("%08x\n", ret);
    return 0;
}

unsigned int reverse(unsigned int num)
{
    unsigned int res;
    unsigned int temp;
    //位左移，右移秒杀了 学习一下
    for (int i = 0; i < 32; i++)
    {
        temp = (num >> i) & 1;
        res = res | (temp << 31 - i);
    }
    return res;
}