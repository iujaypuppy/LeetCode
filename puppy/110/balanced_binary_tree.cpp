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
    bool isBalanced(TreeNode* root) {
        int height(0);
        return is_Balanced(root, height, 1);
    }
    
    bool is_Balanced(TreeNode* node, int& height, int level) {
        if (node == NULL) {
            return true;
        }
        height = (height > level) ? height : level;
        
        int left_height(height);
        int right_height(height);
        bool left_balanced = is_Balanced(node->left, left_height, level + 1);
        bool right_balanced = is_Balanced(node->right, right_height, level + 1);
        
        height = (left_height > right_height) ? left_height : right_height;
        
        return left_balanced && right_balanced && ((abs(left_height - right_height)) <= 1);
    } 
};
