// 重建二叉树

#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) 
        : val(x)
        ,left(NULL)
        ,right(NULL) 
    {}
    
};

class Solution {
    TreeNode* _reConstructBinaryTree(vector<int>& pre, int pre_start, int pre_end, vector<int>& vin, int vin_start, int vin_end)
    {
        if (vin_start > vin_end || pre_start > pre_end)
            return nullptr;

        TreeNode* root = new TreeNode(pre[pre_start]);
        for (int i = 0; i <= vin_end; ++i)
        {
            //在中序中找到根节点的位置  
            //前序 pre_start ,[pre_start + 1, pre_start + 1 + i - vin_start - 1 ], [pre_start + 1 + i - vin_start - 1 + 1, pre_end]  
            //中序： [vin_start, i) , i , [i+1, vin_end]
            if (pre[pre_start] == vin[i])
            {
                root->left = _reConstructBinaryTree(pre, pre_start + 1, pre_start + i - vin_start, vin, vin_start, i - 1);
                root->right = _reConstructBinaryTree(pre, pre_start + i - vin_start + 1, pre_end, vin, i+1, vin_end);
                break;
            }
        }
        return root;
    }

public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty() || pre.size() != vin.size())
            return nullptr;

        return _reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};