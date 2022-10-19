 // ��������˳��ʹ����λ��ż��ǰ��  �������������˼�����չʹ��

/*
	����һ������Ϊ n �������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�沿�֣�
	���е�ż��λ������ĺ��沿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/

#include<vector>
using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        int k = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            if ((array[i] & 1) == 1) //�������������ң�ÿ�������ģ�������ǰ���������һ������Ҫ������k�±괦
            {
                int tmp = array[i]; //�洢��ǰ����

                int j = i;
                while (j > k)
                {
                    array[j] = array[j - 1];
                    --j;
                }
                array[k++] = tmp;
            }
        }
        return array;
    }
};



class Solution2 {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        int k = array.size() - 1;
        for (int i = array.size() - 1; i >= 0; --i)
        {
            if ((array[i] & 1) == 0) //ż������������ÿ�������ģ�������ǰ���ż����һ������Ҫ������k�±괦
            {
                int tmp = array[i]; //�洢��ǰo��

                int j = i;
                while (j < k)
                {
                    array[j] = array[j + 1];
                    ++j;
                }
                array[k--] = tmp;
            }
        }
        return array;
    }
};