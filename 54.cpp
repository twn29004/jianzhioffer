/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 关于二叉搜索数的介绍
 // https://zh.wikipedia.org/wiki/%E4%BA%8C%E5%85%83%E6%90%9C%E5%B0%8B%E6%A8%B9
class Solution {
private:
    stack<TreeNode*> treeStack;
public:
    /*
    * 对于二叉搜索数的中序遍历是一个有序序列，但是该序列是一个递增的，
    * 我们可以使用先访问右子树的方法进行遍历，这样可以得到一个递减的，便可以得到第k大的数了。
    */
    // 中序遍历的递归写法
    void midErgodic(TreeNode* root, int& k, int& res) {
       if(root->right) {
           midErgodic(root->right, k, res);
       }
       k --;
       if(k == 0) {
           res = root->val;
           return;
       }
       if(root->left) {
           midErgodic(root->left, k, res);
       }
    }
    // 中序遍历的非递归写法
    // 中序遍历采用的数据结构为栈，
    int kthLargest(TreeNode* root, int& k) {
        TreeNode* tmp = root;
        while(k) {
            // 首先是入栈
            if(tmp) {
                treeStack.push(tmp);
            }
            while(tmp->right) {
                treeStack.push(tmp->right);
                tmp = tmp->right;
            }
            // 弹出栈顶元素
            tmp = treeStack.top();
            treeStack.pop();
            k --;
            if(k == 0) {
                return tmp->val;
            }
            while(tmp->left == NULL) {
                tmp = treeStack.top();
                treeStack.pop();
                k --;
                if(k == 0) {
                    return tmp->val;
                }
            }
            tmp = tmp->left;
        }
        return -1;
    }
};



void midErgodic(TreeNode* root) {
    strack<TreeNode*> treeStack;
    treeStack.push(root);
    TreeNode* tmp = root;
    while (!treeStack.empty()) {
        // 入栈
        while(tmp->right) {
            treeStack.push(tmp->right);
            tmp = tmp->right;
        }
        // 当没有右子树时，出栈
        tmp = treeStack.top();
        treeStack.pop();
        cout<<tmp->val<<" ";
        // 当没有左子树时，持续出栈
        while(!tmp->left) {
            tmp = treeStack.top();
            treeStack.pop();
            cout<<tmp->val<<" ";
        }
        // 转到入栈部分
        tmp = tmp->left;
    }
}