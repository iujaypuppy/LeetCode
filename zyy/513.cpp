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
    void findBottomLeftValue(TreeNode *root, int currentLevel, int &level, int &ret) {
        if (root->right != NULL) {
            findBottomLeftValue(root->right, currentLevel + 1, level, ret);
        }
        if (currentLevel >= level) {
            level = currentLevel;
            ret = root->val;
        }
        if (root->left != NULL) {
            findBottomLeftValue(root->left, currentLevel + 1, level, ret);
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int level(0), ret;
        findBottomLeftValue(root, 0, level, ret);
        return ret;
    }
};
