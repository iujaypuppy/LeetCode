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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        level_order_bottom(root, 1, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void level_order_bottom(TreeNode* node, int level, vector<vector<int>>& res) {
        if (node == NULL) {
            return;
        }
        if (res.size() < level) {
            res.push_back(vector<int>(1, node->val));
        } else {
            res[level - 1].push_back(node->val);
        }
        level_order_bottom(node->left, level + 1, res);
        level_order_bottom(node->right, level + 1, res);
    }
};
