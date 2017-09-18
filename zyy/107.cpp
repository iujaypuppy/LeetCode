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
    void levelOrderBottomRecursive(TreeNode *root, size_t level,
                                   vector<vector<int>> &result) {
        if (root == NULL) {
            return;
        }

        if (level >= result.size()) {
            result.resize(level + 1);
        }

        result[level].push_back(root->val);
        levelOrderBottomRecursive(root->left, level + 1, result);
        levelOrderBottomRecursive(root->right, level + 1, result);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderBottomRecursive(root, 0, result);
        reverse(result.begin(), result.end());
        return result;
    }
};
