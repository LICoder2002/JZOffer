//数组中出现次数超过一半的数字
/*
给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组[1, 2, 3, 2, 2, 2, 5, 4, 2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2
*/


#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//思路一：定义map，使用<数字，次数>的映射关系，最后统计每个字符出现的次数

class Solution1 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> m;
        for (auto e : numbers)
        {
            m[e]++;
        }

        for (auto e : numbers)
        {
            if (m[e] > numbers.size() / 2)
            {
                return e;
            }
        }

        return -1;
    }
};

//思路二： 思路二：排序，出现次数最多的数字，一定在中间位置。然后检测中间出现的数字出现的次数是否符合要求

class Solution2 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());

        return numbers[numbers.size() / 2];
    }
};

/*
思路三：目标条件：目标数据超过数组长度的一半，那么对数组，我们同时去掉两个不同的数字，到最后剩下的一个数就是
该数字。如果剩下两个，那么这两个也是一样的，就是结果），在其基础上把最后剩下的一个数字或者两个回到原来数组中，
将数组遍历一遍统计一下数字出现次数进行最终判断。

*/

class Solution3 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int number = numbers[0];
        int times = 1;

        for (int i = 1; i < numbers.size(); ++i)
        {
            if (times == 0) //如果当前times是0，说明前面不同的相互抵消了
            {
                number = numbers[i];
                times = 1;
            }
            else if (number == numbers[i])
            {
                ++times;
            }
            else
            {
                --times;
            }
        }

        int count = 0;
        for (auto num: numbers)
        {
            if (num == number)
                ++count;
        }

        return count > numbers.size() / 2 ? number : -1;
    }
};