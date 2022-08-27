#include<stdio.h>
#define ABS(x) (((x)<0)?-(x):(x))
int main()
{
    int i, b, k = 0;
    for (int i = 1;i <= 5;++i)
    {
        b = i % 2;
        while (b-- >= 0)
            k++;
    }
    printf("%d,%d\n", k, b);
    int m = -5;
    int c = ABS(++m);
    printf("%d\n", c);
    int number, digit;
    number = 13579;
    do
    {
        digit = number % 10;
        printf("%d", digit);
        number = number / 10;
    } while (number != 0);
    int t = 143;
    printf("\n");
    printf("%d", printf("%d", printf("%d", t)));
    int a[10] = { 0 };
    printf("\n");
    printf("%d\n", sizeof(*a));
    int q = 12;
    q += q -= q *= q & q;
    printf("%d\n", q);

    // unsigned char* p1;
    // unsigned long* p2;
    // p1 = (unsigned char*)0x801000;
    // p2 = (unsigned long*)0x810000;
    // printf("%d\n", p1 + 5);
    // printf("%d\n", p2 + 5);

    int arr[3][4] = { {0,1,2,3 },
    {2,3,4,5},
    {3,4,5,6} };
    int(*ptr)[3][4] = &arr;
    printf("%d\n", (*ptr)[1][3]);//注意：数组指针要加*，要加括号，才能取到数组中的元素，因为*解引用第一层是数组
}