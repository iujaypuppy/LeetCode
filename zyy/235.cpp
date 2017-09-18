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
    TreeNode *LCARecursive(TreeNode *root, TreeNode *p, TreeNode *q,
                           bool &pFound, bool &qFound) {
        if (root == NULL) {
            pFound = false;
            qFound = false;
            return NULL;
        }

        TreeNode *lcaLeft, *lcaRight, *lca;
        bool pFoundLeft, pFoundRight, qFoundLeft, qFoundRight;
        lcaLeft = LCARecursive(root->left, p, q, pFoundLeft, qFoundLeft);
        lcaRight = LCARecursive(root->right, p, q, pFoundRight, qFoundRight);
        lca = lcaLeft == NULL ? lcaRight : lcaLeft;
        pFound = pFoundLeft || pFoundRight || p == root;
        qFound = qFoundLeft || qFoundRight || q == root;

        return pFound && qFound && lca == NULL ? root : lca;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        bool pFound, qFound;
        return LCARecursive(root, p, q, pFound, qFound);
    }
};
