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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) {
            return res;
        }
        binary_tree_paths(root, "", res);
        return res;
    }
    
    void binary_tree_paths(TreeNode* node, string path, vector<string>& res) {
        if (node == NULL) {
            return;
        }
        path += (path == "") ? "" : "->";
        path += to_string(node->val);
        if (node->left == NULL && node->right == NULL) {
            res.push_back(path);
            return;
        }
        binary_tree_paths(node->left, path, res);
        binary_tree_paths(node->right, path, res);
    }
};
