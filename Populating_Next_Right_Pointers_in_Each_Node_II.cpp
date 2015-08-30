/*
将左孩子连接到右孩子或者更右端的下一个结点
将右孩子连接到更右端的下一个结点。
*/
class Solution {
private:
    queue<TreeLinkNode *> Que;
public:
    TreeLinkNode* findNext(TreeLinkNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->left != NULL)
        {
            return root->left;
        }
        else if (root->right != NULL)
        {
            return root->right;
        }
        else
        {
            return findNext(root->next);
        }
    }
    void connect(TreeLinkNode *root) {
        if (root != NULL)
        {
            Que.push(root);
        }
        while (!Que.empty())
        {
            TreeLinkNode *node = Que.front();
            Que.pop();
            if (node->left != NULL)
            {
                Que.push(node->left);
            }
            if (node->right != NULL)
            {
                Que.push(node->right);
            }
            if (node== NULL)
            {
                return;
            }
            if (node->left != NULL)
            {
                if (node->right != NULL)
                {
                    node->left->next = node->right;
                }
                else
                {
                    node->left->next = findNext(node->next);
                }
            }
            if (node->right != NULL)
            {
                node->right->next = findNext(node->next);
            }
        }
    }
};