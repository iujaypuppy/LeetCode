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
    bool hasPathSum(TreeNode* root, int sum) {
        return has_path_sum(root, sum, 0);
    }
    
    bool has_path_sum(TreeNode* node, int sum, int count) {
        if (node == NULL) {
            return false;
        }
        if (count + node->val == sum && node->left == NULL && node->right == NULL) {
            return true;
        }
        return has_path_sum(node->left, sum, count + node->val)
            || has_path_sum(node->right, sum, count + node->val);
    }
};
