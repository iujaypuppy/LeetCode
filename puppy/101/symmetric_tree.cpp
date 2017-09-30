/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return is_symmetric(root->left, root->right);
    }
    bool is_symmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) {
            return !((left == NULL) ^ (right == NULL));
        }
        if (left->val != right->val) {
            return false;
        }
        return is_symmetric(left->left, right->right)
            && is_symmetric(left->right, right->left);
    }
};
