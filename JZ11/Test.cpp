//JZ11 旋转数组的最小数字

/*
有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，
比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。
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
            if (right - left == 1) //两个下标相邻
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
                //mid在前半部分
                left = mid;
            }
            else 
            {
                //mid在后半部分
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
        //要一直满足该条件，以证明旋转特性
        while (rotateArray[left] >= rotateArray[right]) {
            if (right - left == 1) {
                //两个下标已经相邻了
                mid = right;
                break;
            }
            mid = left + ((right - left) >> 1); //注意操作符优先级
            if (rotateArray[mid] == rotateArray[left] && rotateArray[left] ==
                rotateArray[right]) {
                //无法判定目标数据在mid左侧，还是右侧我们采用线性遍历方式
                int result = rotateArray[left];
                for (int i = left + 1; i < right; i++) {
                    if (result > rotateArray[i]) {
                        result = rotateArray[i];
                    }
                }
                return result;
            }
            if (rotateArray[mid] >= rotateArray[left]) { //试想两者相等， 隐含条件rotateArray[left] >= rotateArray[right]
                    //说明mid在前半部分
                    left = mid;
            }
            else {//说明mid在后半部分
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};