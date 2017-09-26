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
    TreeNode *constructMaximumBinaryTree(vector<int>::iterator begin,
                                         vector<int>::iterator end) {
        if (begin == end) {
            return NULL;
        }

        vector<int>::iterator max(end);
        for (vector<int>::iterator i(begin); i != end; i++) {
            if (max == end || *i > *max) {
                max = i;
            }
        }

        TreeNode *root(new TreeNode(*max));
        root->left = constructMaximumBinaryTree(begin, max);
        root->right = constructMaximumBinaryTree(max + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums.begin(), nums.end());
    }
};
