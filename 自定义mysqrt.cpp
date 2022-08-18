#include<iostream>
#include<iomanip>//必要头文件
using namespace std;
// 请用计算并输出sqrt(23)，不适用系统库函数
// 输出4后面的小数点后10位，不多也不少
/*
 * function:牛顿迭代法实现sqrt()
 */
const double eps=1e-10;
double mysqrt(float n)
{
    double init_value = n;// 牛顿法需要选择一个初始值，这里使等于n
    double x = init_value;// return value
    double last;// 保留上一次的结果

    do{

        last = x;
        x = (x + n/x)/2;

    }while(abs(x - last) > eps);// 比abs(x-n/x)>eps更精确

    return x;
}


int main()
{
    int a=23;
    double ans=mysqrt(a);
    cout<<fixed<<setprecision(10)<<ans<<endl;
}