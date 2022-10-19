//JZ11 ��ת�������С����

/*
��һ������Ϊ n �ķǽ������飬����[1,2,3,4,5]������������ת������һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����һ����ת���飬
��������[3,4,5,1,2]������[4,5,1,2,3]�����ġ����ʣ���������һ����ת���飬�������е���Сֵ��
*/

#include<vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;

        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;

        while (rotateArray[left] >= rotateArray[right])  // 1 2  2 2  2  2 
        {
            if (right - left == 1) //�����±�����
            {
                mid = right; 
                break;
            }

            mid = (left + right) >> 1;

            if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid])
            {
                int target = rotateArray[left];
                for (int i = left + 1; i < right; ++i)
                {
                    if (target > rotateArray[i])
                    {
                        target = rotateArray[i];
                    }
                }
                return target;

            }

            if (rotateArray[mid] >= rotateArray[left])
            {
                //mid��ǰ�벿��
                left = mid;
            }
            else 
            {
                //mid�ں�벿��
                right = mid;
            }
        }

        return rotateArray[mid];
    }
};


class Solution2 {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) {
            return 0;
        }

        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        //Ҫһֱ�������������֤����ת����
        while (rotateArray[left] >= rotateArray[right]) {
            if (right - left == 1) {
                //�����±��Ѿ�������
                mid = right;
                break;
            }
            mid = left + ((right - left) >> 1); //ע����������ȼ�
            if (rotateArray[mid] == rotateArray[left] && rotateArray[left] ==
                rotateArray[right]) {
                //�޷��ж�Ŀ��������mid��࣬�����Ҳ����ǲ������Ա�����ʽ
                int result = rotateArray[left];
                for (int i = left + 1; i < right; i++) {
                    if (result > rotateArray[i]) {
                        result = rotateArray[i];
                    }
                }
                return result;
            }
            if (rotateArray[mid] >= rotateArray[left]) { //����������ȣ� ��������rotateArray[left] >= rotateArray[right]
                    //˵��mid��ǰ�벿��
                    left = mid;
            }
            else {//˵��mid�ں�벿��
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};