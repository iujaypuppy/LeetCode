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
    bool match(TreeNode *s, TreeNode *t) {
        if (t == NULL || s == NULL) {
            return s == t;
        }

        return s->val == t->val &&
                match(s->left, t->left) &&
                match(s->right, t->right);
    }

    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (t == NULL) {
            return true;
        }

        if (s == NULL) {
            return false;
        }

        if (s->val == t->val) {
            if (match(s, t)) {
                return true;
            }
        }

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
