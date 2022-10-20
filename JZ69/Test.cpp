//��̨��
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ�� n ����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
#include<vector>
using namespace std;

//����һ���򵥶��鷽ʽ
//״̬���壺f(i): ����į�׵�������
//״̬���ƣ�f(i) = f(i-1)+f(i-2)
//��ʼ״̬: f(0) = 1��0̨�ף�������㣬����0̨�׵ķ�����һ�֣����ǲ���[��������е���֣��������룬�����
//������Ϊ0����˵�������ܿ�ʼ...]��, f(1) = 1;
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

//������������

class Solution2 {
public:
    int jumpFloor(int number) {
        int first = 1; //��һ��̨��
        int second = 2;//�ڶ���̨��
        int third = 0; //����nֱ�ӾͿ�����f(1) = 1 && f(2) = 2�����
        while (number > 2) {
            third = first + second;
            first = second;
            second = third;
            --number;
        }
        return third;
    }
};
