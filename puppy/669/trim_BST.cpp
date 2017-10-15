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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        trimNode(root, L, R);
        return root;
    }
    
    void trimNode(TreeNode*& node, int L, int R) {
        if (node == NULL) {
            return;
        }
        if (L > node->val) {
            node = node->right;
            trimNode(node, L, R);
        } else if (R < node->val) {
            node = node->left;
            trimNode(node, L, R);
        } else {
            trimNode(node->left, L, R);
            trimNode(node->right, L, R);
        }
    }
};
