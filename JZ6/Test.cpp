//从尾到头打印链表

//输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。

#include<vector>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x)
        :val(x), next(NULL) 
    {}
};


//方法一，stack方式，这种方式会有内存占用过多的问题

class Solution1 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        vector<int> v;
        while (head)
        {
            s.push(head->val);
            head = head->next;
        }

        while (!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};


//方法二，逆置
class Solution2{
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        reverse(v.begin(), v.end());

        return v;
    }
};

//方法三，递归

class Solution3 {
    void _printListFromTailToHead(ListNode* head, vector<int>& v)
    {
        if (nullptr == head)
            return;

        _printListFromTailToHead(head->next, v);
        v.push_back(head->val);
    }
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        _printListFromTailToHead(head, v);
        return v;
    }
};