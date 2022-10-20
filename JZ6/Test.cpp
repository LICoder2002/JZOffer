//��β��ͷ��ӡ����

//����һ�������ͷ�ڵ㣬�������β��ͷ��˳�򷵻�ÿ���ڵ��ֵ�������鷵�أ���

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


//����һ��stack��ʽ�����ַ�ʽ�����ڴ�ռ�ù��������

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


//������������
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

//���������ݹ�

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