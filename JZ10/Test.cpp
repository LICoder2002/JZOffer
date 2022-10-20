//斐波那契数列 现在要求输入一个正整数 n ，请你输出斐波那契数列的第 n 项。

//方法一：迭代
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
//方法二：递归 + map 剪枝
class Solution2 {
    
    unordered_map<int, int> filter;

public:
    int Fibonacci(int n) {
        if (0 == n || 1 == n)
            return n;

        int ppre = 0;
        if (filter.find(n - 2) == filter.end()) //没找到
        {
            ppre = Fibonacci(n - 2);
            filter.insert({ n - 2, ppre });
        }
        else
        {
            ppre = filter[n - 2];
        }

        int pre = 0;
        if (filter.find(n - 1) == filter.end())// 没有找到
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