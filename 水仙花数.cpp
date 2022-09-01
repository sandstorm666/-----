class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param n int整型 
     * @return bool布尔型
     */
    bool check(int n) {
        int a = 0, b = 0, c = 0;//个，十，百
        if (n < 1000)
        {
            a = n % 10;
            b = n / 10 % 10;
            c = n / 100;
            if (a * a * a + b * b * b + c * c * c == n)
            {
                return true;
            }
        }
        return false;
    }
};