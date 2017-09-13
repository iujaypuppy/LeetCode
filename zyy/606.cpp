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
    string tree2str(TreeNode* t) {
        if (t == NULL) {
            return "";
        }

        string left(tree2str(t->left)), right(tree2str(t->right)), result(to_string(t->val));
        if (right != "") {
            return result + "(" + left + ")(" + right + ")";
        }
        if (left != "") {
            return result + "(" + left + ")";
        }

        return result;
    }
};
