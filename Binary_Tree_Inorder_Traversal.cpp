/*
二叉树的非递归中序遍历
1. 将根结点入栈，如果左孩子不为空，将左孩子入栈
2. 如果到了最下面的左孩子，将其出栈输出，并将根结点设置为当前栈顶结点的右孩子
3. 继续入栈左孩子
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *p = root;
        stack<TreeNode*> stk;
        vector<int> vec;
        while (p != NULL || !stk.empty())
        {
            while (p)
            {
                stk.push(p);
                p = p->left;
            }
            if (!stk.empty())
            {
                vec.push_back(stk.top()->val);
                p = stk.top()->right;
                stk.pop();
            }
        }
        return vec;
    }
};