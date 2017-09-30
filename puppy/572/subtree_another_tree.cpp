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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL || t == NULL) {
            return s == NULL && t == NULL;
        }
        bool is_same = false;
        if (s->val == t->val) {
            is_same = is_same_tree(s, t);
        }
        return is_same || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool is_same_tree(TreeNode* a, TreeNode* b) {
        if (a == NULL || b == NULL) {
            return a == NULL && b == NULL;
        }
        if (a->val != b->val) {
            return false;
        }
        return is_same_tree(a->left, b->left) && is_same_tree(a->right, b->right);
    }
};
