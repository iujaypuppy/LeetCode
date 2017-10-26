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
    /* This return how many nodes are there in this (sub)tree */
    int kthSmallest(TreeNode *root, int k,
                    TreeNode *&ret) {
        if (root == NULL) {
            ret = NULL;
            return 0;
        }

        int leftSize(kthSmallest(root->left, k, ret));
        if (ret != NULL) {
            return leftSize + 1;
        }
        if (leftSize + 1 == k) {
            ret = root;
            return leftSize + 1;
        }
        return leftSize + 1 + kthSmallest(root->right, k - 1 - leftSize, ret);
    }

    int kthSmallest(TreeNode* root, int k) {
        TreeNode *ret(NULL);
        kthSmallest(root, k, ret);
        return ret->val;
    }
};
