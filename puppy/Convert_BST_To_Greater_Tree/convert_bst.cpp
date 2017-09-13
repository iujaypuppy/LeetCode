/* Deginition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> vals;
        get_nodes_vals(root, vals);
        update_nodes(root, vals);
        return root;
    }
    
    void update_nodes(TreeNode* node, vector<int>& vals) {
        if (node == NULL) {
            return;
        }
        set_node_val(node, vals);
        update_nodes(node->left, vals);
        update_nodes(node->right, vals);
    }
    
    void set_node_val(TreeNode* node, vector<int>& vals) {
        int val = node->val;
        for (vector<int>::iterator iter(vals.begin()); iter != vals.end(); iter++) {
            if (*iter > node->val) {
                val += *iter;
            }
        }
        node->val = val;
    }
    
    void get_nodes_vals(TreeNode* node, vector<int>& vals) {
        if (node == NULL) {
            return;
        }
        vals.push_back(node->val);
        get_nodes_vals(node->left, vals);
        get_nodes_vals(node->right, vals);
    }
   
};
