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
    void sumNumbers(TreeNode *root, int cur, int &sum) {
        if (root == NULL) {
            return;
        }
        cur = cur * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += cur;
            return;
        }
        sumNumbers(root->left, cur, sum);
        sumNumbers(root->right, cur, sum);
    }
    int sumNumbers(TreeNode* root) {
        int ret(0);
        if (root == NULL) {
            return ret;
        }
        sumNumbers(root, 0, ret);
        return ret;
    }
};
