/*
树的先序遍历，不能使用递归的方法。
使用Stack来实现，关键在于入栈的顺序，先入右孩子，后入左孩子。
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        if (root == NULL)
        {
            return vec;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            if (node->right != NULL)
            {
                stk.push(node->right);
            }
            if (node->left != NULL)
            {
                stk.push(node->left);
            }
            vec.push_back(node->val);
        }
        return vec;
    }
};