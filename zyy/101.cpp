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
    bool isSymmetric(TreeNode *a, TreeNode *b) {
        if (a == NULL || b == NULL) {
            return a == b;
        }

        return a->val == b->val &&
                isSymmetric(a->left, b->right) &&
                isSymmetric(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetric(root->left, root->right);
    }
};
