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
    void maxDepthRecursive(TreeNode *root, int level, int &max) {
        if (root == NULL) {
            if (level > max) {
                max = level;
            }
            return;
        }

        maxDepthRecursive(root->left, level + 1, max);
        maxDepthRecursive(root->right, level + 1, max);
    }
    int maxDepth(TreeNode* root) {
        int result;
        maxDepthRecursive(root, 0, result);
        return result;
    }
};
