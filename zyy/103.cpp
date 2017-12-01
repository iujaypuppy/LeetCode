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
    void zigzagLevelOrder(TreeNode *root, int level, vector<vector<int>> &ret) {
        if (root == NULL) {
            return;
        }
        if (level >= ret.size()) {
            ret.resize(level + 1);
        }
        if (level % 2 == 0) {
            ret[level].push_back(root->val);
        } else {
            ret[level].insert(ret[level].begin(), root->val);
        }
        zigzagLevelOrder(root->left, level + 1, ret);
        zigzagLevelOrder(root->right, level + 1, ret);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        zigzagLevelOrder(root, 0, ret);
        return ret;
    }
};
