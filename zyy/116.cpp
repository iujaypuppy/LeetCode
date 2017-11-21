/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
  public:
    void connect(TreeLinkNode *root) {
        for (TreeLinkNode *i(root); i != NULL; i = i->left) {
            for (TreeLinkNode *j(i); j != NULL; j = j->next) {
                if (j ->left == NULL || j->right == NULL) {
                    continue;
                }
                j->left->next = j->right;
                if (j->next != NULL) {
                    j->right->next = j->next->left;
                }
            }
        }
    }
};
