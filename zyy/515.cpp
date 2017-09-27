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
    void largestValues(TreeNode *root, size_t level, vector<int> &largest) {
        if (root == NULL) {
            return;
        }

        if (level >= largest.size()) {
            largest.resize(level + 1);
            largest[level] = root->val;
        }
        largest[level] = max(root->val, largest[level]);
        largestValues(root->left, level + 1, largest);
        largestValues(root->right, level + 1, largest);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        largestValues(root, 0, ret);
        return ret;
    }
};
