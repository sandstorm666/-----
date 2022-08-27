#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mk_cp(vector<int>& cps)
{
    int cnt = cps[3];//先取出4人组
    int thr = cps[2];
    int dou = cps[1];
    int single = cps[0];


    cout << "signle = " << single << endl;
    cout << "dou = " << dou << endl;
    cout << "thr = " << thr << endl;
// 3人组和一人组配对
    cout << "cnt = " << cnt << endl;
    cnt += min(thr, single);
    if (single >= thr)
    {
        single -= thr;
    }
    else
        single = 0;//没有单人组了
    // 2人和2人或者2人和1人;
    cout << "cnt = " << cnt << endl;
    cnt += dou / 2;
    cout << "cnt = " << cnt << endl;
    cout << "dou = " << dou << endl;
    if (dou % 2)//奇数
    {
        dou = 1;//一个2人组
        cout << "single = " << single << endl;
        if (single >= 2)
        {
            cnt += 1;
            cout << "single >=2 cnt = " << cnt << endl;
            single -= 2;
        }
    }
    // 4个人组
    cout << "cnt = " << cnt << endl;
    cnt += single / 4;
    cout << "cnt = " << cnt << endl;
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cps;
    while (n--)
    {
        vector<int> t;
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        t.emplace_back(A);
        t.emplace_back(B);
        t.emplace_back(C);
        t.emplace_back(D);
        cps.push_back(t);
    }
    for (int i = 0;i < cps.size();++i)
    {
        int x = mk_cp(cps[i]);
        cout << x << endl;
    }
    cout << endl;
    return 0;
}