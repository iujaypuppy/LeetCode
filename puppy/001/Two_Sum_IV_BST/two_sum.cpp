/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        map<int, bool> m;
        return find_target(root, k, m);
    }
    bool find_target(TreeNode* root, int target, map<int, bool>& m) {
        if (root == NULL) {
            return false;
        }
        if(m.find(target-root->val) != m.end()) {
            return true;
        }
        m.insert(pair<int, bool>(root->val, true));
        return find_target(root->left, target, m) || find_target(root->right, target, m);
    }
};
