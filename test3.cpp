#include<stdio.h>
int fun(int m)
{
    static int n = 0;m /= 2;m = m * 2;
    if (m)
    {
        n = n * m;
        return (fun(m - 2));
    }
    else
        return(n++);
}
int fun1(int x)
{
    int count = 0;
    while (x)
    {
        count++;
        x = x & (x - 1);
    }
    return count;
}
int main()
{
    int x = fun1(500);
    printf("%d\n", x);
}