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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum(0);
        sum_left_leaves(root, sum, false);
        return sum;
    }
    
    void sum_left_leaves(TreeNode* node, int& sum, bool left) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            sum += (left) ? node->val : 0;
            return;
        } 
        sum_left_leaves(node->left, sum, true);   
        sum_left_leaves(node->right, sum, false);
        
    }
};
