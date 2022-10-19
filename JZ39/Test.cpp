//�����г��ִ�������һ�������
/*
��һ������Ϊ n �����飬��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������[1, 2, 3, 2, 2, 2, 5, 4, 2]����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2
*/


#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//˼·һ������map��ʹ��<���֣�����>��ӳ���ϵ�����ͳ��ÿ���ַ����ֵĴ���

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

//˼·���� ˼·�������򣬳��ִ����������֣�һ�����м�λ�á�Ȼ�����м���ֵ����ֳ��ֵĴ����Ƿ����Ҫ��

class Solution2 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());

        return numbers[numbers.size() / 2];
    }
};

/*
˼·����Ŀ��������Ŀ�����ݳ������鳤�ȵ�һ�룬��ô�����飬����ͬʱȥ��������ͬ�����֣������ʣ�µ�һ��������
�����֡����ʣ����������ô������Ҳ��һ���ģ����ǽ��������������ϰ����ʣ�µ�һ�����ֻ��������ص�ԭ�������У�
���������һ��ͳ��һ�����ֳ��ִ������������жϡ�

*/

class Solution3 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int number = numbers[0];
        int times = 1;

        for (int i = 1; i < numbers.size(); ++i)
        {
            if (times == 0) //�����ǰtimes��0��˵��ǰ�治ͬ���໥������
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