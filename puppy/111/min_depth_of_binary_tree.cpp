tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int res(0x7fffffff);
        minDepth(root, res, 1);
        return res;
    }
    
    void minDepth(TreeNode* node, int& min, int level) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            min = (min < level) ? min : level;
            return;
        }
        minDepth(node->left, min, level + 1);
        minDepth(node->right, min, level + 1);
    }
};
