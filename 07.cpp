/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 总体思想是输入前序遍历和后续遍历的左右边界，根据这个边界来构造二叉树，
    // 首先从先序遍历中数组中找到根节点，然后再根据根节点再后序遍历中找到左右子树的边界
    // 递归的调用该函数
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, 
        int preleft, int preright, int inleft, int inright) {
        // 注意递归终止条件，有两种情况
        if(preleft > preright) {
            return NULL;
        }
        // 首先获得根结点
        TreeNode* root = new TreeNode;
        root->val = preorder[preleft];
        if(preleft == preright) {
            return root;
        }
        // 然后找到左右子树的先序遍历和中序遍历的数组
        int i = inleft;
        for(; i < inright; i ++) {
            if(root->val == inorder[i]) {  // 注意这是建立在二叉树中没有重复元素的基础上的
                break;
            }
        }
        // loc表示根在中序遍历中的位置
        int loc = i;
        // 所以左子树的中序遍历的数组的起始就是[inleft, i - 1],右子树的起始时[i + 1, inright]
        // 这个时候根据这个的长度获得前需遍历的数组的起始
        int len = loc - inleft;
        // 所以左子树的前序遍历的起始就是[preleft + 1, preleft + len],右子树先序遍历的起始就是[preleft + len + 1, preright]
        // 由此便可以根据这个递归的构建左子树
        root->left = build(preorder, inorder, preleft + 1, preleft + len, inleft, loc - 1);
        // 同理构建右子树
        root->right = build(preorder, inorder, preleft + len + 1, preright, loc + 1, inright);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sizeVect1 = preorder.size();
        int sizeVect2 = inorder.size();
        if(sizeVect1 != sizeVect2) {
            return NULL;
        }
        TreeNode* root = build(preorder, inorder, 0, sizeVect1 - 1, 0, sizeVect2 - 1);
        return root;
    }
};