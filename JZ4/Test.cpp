//��ά�����еĲ���
/*
��һ����ά����array�У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]
���� target = 7������ true��

���� target = 3������ false��


*/

#include<vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i = 0; 
        int j = array[0].size() - 1;

        while (i < array.size() && j >= 0) 
        {
            if (target < array[i][j]) //array[i][j] �ǵ�ǰ�����ģ��ǵ�ǰ����С��
            {
                --j; // �ų���ǰ��
            }
            else if (target > array[i][j]) //array[i][j] �ǵ�ǰ�����ģ��ǵ�ǰ����С��
            {
                ++i; // �ų���ǰ��
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};