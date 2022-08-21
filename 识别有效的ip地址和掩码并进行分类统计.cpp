#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
// 请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。
// 所有的IP地址划分为 A,B,C,D,E五类
// A类地址从1.0.0.0到126.255.255.255;
// B类地址从128.0.0.0到191.255.255.255;
// C类地址从192.0.0.0到223.255.255.255;
// D类地址从224.0.0.0到239.255.255.255；
// E类地址从240.0.0.0到255.255.255.255
// 私网IP范围是：
// 从10.0.0.0到10.255.255.255
// 从172.16.0.0到172.31.255.255
// 从192.168.0.0到192.168.255.255
// 子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
// （注意二进制下全是1或者全是0均为非法子网掩码）
// 类似于【0...】和【127...】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略
// 一共分为7类：ABCDE，私网IP和非法IP。

/*利用getline每次读取一行，然后依次分割存入vec，注意最后一个数，没有在循环内入vec，出循环时需要手动入vec
 先判断ip地址是否合法，不合法直接下一个；ip合法后判断子网掩码是否合法，子网掩码的判断繁琐点，需要分两步，
 先找到非全1的数，在判断后面是否全0，使用下标帮助判断。
 最后分类。
 */
int main()
{
    vector<int> arr(7, 0); //分别对应题目的7个类别
    string s;
    // 注意根据符号分割是，最后一段数字没有入vec，需要单独判断容器
    while (getline(cin, s))
    {
        int n = s.length();
        vector<int> ips;    //记录ip地址的数字
        bool bad = false;   //是否是非法地址
        bool isnum = false; //判断是否是数字
        int num = 0;
        for (int i = 0; i < n; i++)
        { //遍历该ip字符串
            if (s[i] == '.' || s[i] == '~')
            { //以.或者~分割
                if (isnum)
                {
                    if (num > 255)
                    {
                        bad = true; //错误ip，数字不能超过255
                        break;
                    }
                    ips.push_back(num);
                    isnum = false;
                    num = 0;
                }
                else
                {
                    arr[5]++; //错误地址
                    bad = true;
                    break;
                }
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                isnum = true;
                num = num * 10 + s[i] - '0'; //计算数字
            }
            else
            {
                arr[5]++;
                isnum = false; //错误地址，数字部分还有非数字
                bad = true;
                break;
            }
        }
        if (isnum)
            ips.push_back(num); //最后一个数字
        if (ips[0] == 0 || ips[0] == 127 || bad)
            continue; //忽略0或者127开头的地址，错误ip已经统计了过了，可以忽略
        int mask = 4; //查看掩码的数字 ips的0~3代表ip
        while (mask < 8 && ips[mask] == 255)
            mask++; //找到掩码第一个不全为1的数
        if (mask == 8)
        { //掩码全1也是不合法
            arr[5]++;
            continue;
        }
        //各类掩码含1的最后一位 128是只有第一位有1了
        else if (ips[mask] == 254 || ips[mask] == 252 || ips[mask] == 248 || ips[mask] == 240 || ips[mask] == 224 || ips[mask] == 191 || ips[mask] == 128)
            mask++;
        while (mask < 8 && ips[mask] == 0)
            mask++;
        if (mask != 8)
        { //掩码后半部分不能有1
            arr[5]++;
            continue;
        }
        if (ips[0] >= 1 && ips[0] <= 126)
            arr[0]++; // A类地址
        else if (ips[0] >= 128 && ips[0] <= 191)
            arr[1]++; // B类地址
        else if (ips[0] >= 192 && ips[0] <= 223)
            arr[2]++; // C类地址
        else if (ips[0] >= 224 && ips[0] <= 239)
            arr[3]++; // D类地址
        else if (ips[0] >= 240 && ips[0] <= 255)
            arr[4]++; // E类地址
        if (ips[0] == 10)
            arr[6]++; //私有地址10开头的
        else if (ips[0] == 172 && (ips[1] >= 16 && ips[1] <= 31))
            arr[6]++; //私有地址172.16.0.0-172.31.255.255
        else if (ips[0] == 192 && ips[1] == 168)
            arr[6]++; //私有地址192.168.0.0-192.168.255.255
    }
    for (int i = 0; i < 7; i++)
    { //输出
        cout << arr[i];
        if (i != 6)
            cout << " ";
    }
    cout << endl;
    return 0;
}
