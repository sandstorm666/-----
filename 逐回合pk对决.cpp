class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 输入参数 Ax 角色A的血量，Ay 角色A 的攻击力，Az A的攻击CD，Aw 角色A的恢复力
输入参数 Bx 角色B的血量，By 角色B 的攻击力，Bz B的攻击CD，Bw 角色B的恢复力
     * @param Ax int整型 角色A的血量上限
     * @param Ay int整型 角色A的攻击力
     * @param Az int整型 A的攻击CD
     * @param Aw int整型 角色A的每回合恢复血量值
     * @param Bx int整型 角色B的血量上限
     * @param By int整型 角色B的攻击力
     * @param Bz int整型 B的攻击CD
     * @param Bw int整型 角色B的每回合恢复血量值
     * @return int整型
     */
    //A win 1
    //B win 2
    //AB die 3
    // 假设a先打
    int PK(int Ax, int Ay, int Az, int Aw, int Bx, int By, int Bz, int Bw) {
        int AMax = Ax, BMax = Bx;
        if (Ay <= Az * Bw && By <= Bz * Aw)
            return 4;
        int Ai = 0, Bi = 0;//记录攻击CD
        int i = 0;
        while (true)
        {
            if (i == Ai)
            {
                Ai = i + Az;//下一次攻击
                Bx -= Ay;
            }
            if (i == Bi)
            {
                Bi = i + Bz;//下一次攻击
                Ax -= By;
            }
            if (Bx <= 0 && Ax > 0)
                return 1;
            else if (Ax <= 0 && Bx > 0)
                return 2;
            else if (Ax <= 0 && Bx <= 0)
                return 3;
            Ax += Aw;
            Bx += Bw;
            //回复值不能超上限
            Ax = Ax > AMax ? AMax : Ax;
            Bx = Bx > BMax ? BMax : Bx;
            ++i;
        }
    }
};