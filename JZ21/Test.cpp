 // 调整数组顺序使奇数位于偶数前面  数组操作，排序思想的扩展使用

/*
	输入一个长度为 n 整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前面部分，
	所有的偶数位于数组的后面部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include<vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        int k = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            if ((array[i] & 1) == 1) //奇数。从左向右，每次遇到的，都是最前面的奇数，一定将来要被放在k下标处
            {
                int tmp = array[i]; //存储当前奇数

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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        int k = array.size() - 1;
        for (int i = array.size() - 1; i >= 0; --i)
        {
            if ((array[i] & 1) == 0) //偶数。从右往左，每次遇到的，都是最前面的偶数，一定将来要被放在k下标处
            {
                int tmp = array[i]; //存储当前o数

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