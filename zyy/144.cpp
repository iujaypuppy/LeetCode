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
    void preorderTraversal(TreeNode *root, vector<int> &out) {
        if (root == NULL) {
            return;
        }
        out.push_back(root->val);
        preorderTraversal(root->left, out);
        preorderTraversal(root->right, out);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorderTraversal(root, ret);
        return ret;
    }
};
