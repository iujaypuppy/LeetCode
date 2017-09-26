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
    int findSecondMinimumValue(TreeNode* root) {
        int min(root->val), second_min(-1);
        find_second_min(root, min, second_min);
        return second_min;
    }
    
    void find_second_min(TreeNode* node, int min, int& second_min) {
        if (node == NULL) {
            return;
        }
        if (node->val > min) {
            second_min = node->val;
            return;
        }
        
        int left(-1), right(-1);
        find_second_min(node->left, min, left);
        find_second_min(node->right, min, right);
        
        if (left == -1) {
            second_min = right;
        } else if (right == -1) {
            second_min = left;
        } else {
            second_min = (left < right) ? left : right; 
        }
    }
};
