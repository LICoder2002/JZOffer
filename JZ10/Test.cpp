//쳲��������� ����Ҫ������һ�������� n ���������쳲��������еĵ� n �

//����һ������
class Solution1 {
public:
    int Fibonacci(int n) {
        if (0 == n)
            return n;

        int first = 1;
        int second = 1;
        int third = 1;
        while (n > 2)
        {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};

#include<unordered_map>
using namespace std;
//���������ݹ� + map ��֦
class Solution2 {
    
    unordered_map<int, int> filter;

public:
    int Fibonacci(int n) {
        if (0 == n || 1 == n)
            return n;

        int ppre = 0;
        if (filter.find(n - 2) == filter.end()) //û�ҵ�
        {
            ppre = Fibonacci(n - 2);
            filter.insert({ n - 2, ppre });
        }
        else
        {
            ppre = filter[n - 2];
        }

        int pre = 0;
        if (filter.find(n - 1) == filter.end())// û���ҵ�
        {
            pre = Fibonacci(n - 1);
            filter.insert({ n - 1, pre });
        }
        else
        {
            pre = filter[n - 1];
        }
        
        return ppre + pre;
    }
};