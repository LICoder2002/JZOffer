//跳台阶
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
#include<vector>
using namespace std;

//方法一：简单动归方式
//状态定义：f(i): 跳到i台阶的总跳法
//状态递推：f(i) = f(i-1)+f(i-2)
//初始状态: f(0) = 1（0台阶，就是起点，到达0台阶的方法有一种，就是不跳[这里可能有点奇怪，但是想想，如果方
//法次数为0，就说明不可能开始...]）, f(1) = 1;
class Solution1 {
public:
    int jumpFloor(int number) {
        vector<int> dp(number + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= number; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number];
    }
};

//方法二：递推

class Solution2 {
public:
    int jumpFloor(int number) {
        int first = 1; //第一个台阶
        int second = 2;//第二个台阶
        int third = 0; //等于n直接就考虑了f(1) = 1 && f(2) = 2的情况
        while (number > 2) {
            third = first + second;
            first = second;
            second = third;
            --number;
        }
        return third;
    }
};
