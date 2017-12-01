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
    void flatten(TreeNode *&tail, TreeNode *node) {
        if (node == NULL) {
            return;
        }

        TreeNode *left(node->left), *right(node->right);
        node->left = NULL;
        node->right = NULL;
        if (node != tail) {
            tail->right = node;
            tail = node;
        }
        flatten(tail, left);
        flatten(tail, right);
    }
    void flatten(TreeNode* root) {
        TreeNode *tail(root);
        flatten(tail, root);
    }
};
