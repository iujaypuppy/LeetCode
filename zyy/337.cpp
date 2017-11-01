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
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left(rob(root->left)), right(rob(root->right));
        int rootNotTaken(left + right);

        int rootTaken(root->val);
        if (root->left != NULL) {
            if (root->left->left != NULL) {
                rootTaken += root->left->left->val;
            }
            if (root->left->right != NULL) {
                rootTaken += root->left->right->val;
            }
        }
        if (root->right != NULL) {
            if (root->right->left != NULL) {
                rootTaken += root->right->left->val;
            }
            if (root->right->right != NULL) {
                rootTaken += root->right->right->val;
            }
        }

        root->val = max(rootTaken, rootNotTaken);
        return root->val;
    }
};
