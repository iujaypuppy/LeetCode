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
    int diameterOfBinaryTree(TreeNode* root) {
        // Use node's val property to store this node's height
        treeNodeHeight(root);
        
        // Each node's diameter = left tree's height + right's tree height
        int res(0);
        diameterOfBinaryTree(root, res);
        
        return res;
    }
    
    void diameterOfBinaryTree(TreeNode* node, int& res) {
        if (node == NULL) {
            return;
        }
        
        int cur(0);
        if (node->left != NULL) {
            cur += node->left->val;
        }
        if (node->right != NULL) {
            cur += node->right->val;
        }
        res = max(res, cur);
        
        diameterOfBinaryTree(node->left, res);
        diameterOfBinaryTree(node->right, res);
    }
    
    int treeNodeHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int height = max(treeNodeHeight(node->left), treeNodeHeight(node->right)) + 1;
        node->val = height;
        return height;
    }
};
