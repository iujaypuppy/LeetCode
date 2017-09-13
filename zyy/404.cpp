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
        if (root == NULL) {
            return NULL;
        }

        int sum(0);
        if (root->left != NULL &&
            root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        } else {
            sum += sumOfLeftLeaves(root->left);
        }

        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
