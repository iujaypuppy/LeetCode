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
    void rightSideView(TreeNode *root, int level, vector<int> &view) {
        if (root == NULL) {
            return;
        }

        if (level >= view.size()) {
            view.resize(level + 1);
        }
        rightSideView(root->left, level + 1, view);
        view[level] = root->val;
        rightSideView(root->right, level + 1, view);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        rightSideView(root, 0, ret);
        return ret;
    }
};
