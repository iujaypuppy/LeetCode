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
    string tree2str(TreeNode* t) {
        string res = "";
        tree_to_str(t, res);
        return res;
    }
    
    void tree_to_str(TreeNode* t, string& str) {
        if (t == NULL) {
            return;
        }
        str += to_string(t->val);
        if (t->left == NULL && t->right == NULL) {
            return;
        } else if (t->left == NULL) {
            str += "()";
            str += "(";
            tree_to_str(t->right, str);
            str += ")";
        } else if (t->right == NULL) {
            str += "(";
            tree_to_str(t->left, str);
            str += ")";
        } else {
            str += "(";
            tree_to_str(t->left, str);
            str += ")";
            str += "(";
            tree_to_str(t->right, str);
            str += ")";
        }      
    }
};
