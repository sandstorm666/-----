class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求取指定长度序列的和
     * @param n int整型 序列长度
     * @return float浮点型
     */
    float seqSum(int n) {
        int a = 1, b = 2;//a记录分子，b记录分母
        int i = 0;
        float sum = 0;
        if (n <= 0)
            return 0;
        else if (n == 1)
        {
            sum += (float)a / b;
        }
        else
        {
            while (i < n)
            {
                sum += (float)a / b;
                int temp = b;
                b = a + b;
                a = temp;
                i++;
            }
        }
        //保留两位小数
        double ans = sum * 1000;//先得到3位小数
        int t = (int)ans % 10;
        if (t > 4)
        {
            ans += 10;//进位
        }
        int res = (int)ans / 10;//转整数
        float x = res / 100.0;
        return x;
    }
};