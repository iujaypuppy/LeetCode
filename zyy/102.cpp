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
    void levelOrder(TreeNode *root, int level, vector<vector<int>> &ret) {
        if (root == NULL) {
            return;
        }

        if (level >= ret.size()) {
            ret.resize(level + 1);
        }
        levelOrder(root->left, level + 1, ret);
        ret[level].push_back(root->val);
        levelOrder(root->right, level + 1, ret);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        levelOrder(root, 0, ret);
        return ret;
    }
};
