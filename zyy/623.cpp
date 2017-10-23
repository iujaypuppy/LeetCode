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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *added(new TreeNode(v));
            added->left = root;
            root = added;
            return root;
        }

        if (root == NULL) {
            return NULL;
        }

        if (d == 2) {
            TreeNode *left(new TreeNode(v));
            left->left = root->left;
            root->left = left;

            TreeNode *right(new TreeNode(v));
            right->right = root->right;
            root->right = right;

            return root;
        }

        root->left = addOneRow(root->left, v, d - 1);
        root->right = addOneRow(root->right, v, d - 1);
        return root;
    }
};
