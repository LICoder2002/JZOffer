//�滻�ո�

/*
	��ʵ��һ����������һ���ַ���s�е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

#include<string>
using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param s string�ַ���
     * @return string�ַ���
     */
    string replaceSpace(string s) {
        // write code here
        string str;
        for (auto ch : s)
        {
            if (ch == ' ')
                str += "%20";
            else
                str += ch;
        }
        return str;
    }
};