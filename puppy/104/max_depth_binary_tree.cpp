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
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        find_max_depth(root, max_depth, 1);
        return max_depth;
    }
    
    void find_max_depth(TreeNode* node, int& max, int level) {
        if (node == NULL) {
            max = (level > max) ? (level - 1) : max;
            return;
        }
        
        find_max_depth(node->left, max, level+1);
        find_max_depth(node->right, max, level+1);
    } 
};
