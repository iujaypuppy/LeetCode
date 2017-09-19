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
    bool isBalancedRecursive(TreeNode *root, int &height) {
        if (root == NULL) {
            height = 0;
            return true;
        }

        int leftHeight, rightHeight;
        if (!isBalancedRecursive(root->left, leftHeight) ||
            !isBalancedRecursive(root->right, rightHeight)) {
            return false;
        }

        height = max(leftHeight, rightHeight) + 1;
        return abs(leftHeight - rightHeight) <= 1;
    }

    bool isBalanced(TreeNode* root) {
        int height;
        return isBalancedRecursive(root, height);
    }
};
