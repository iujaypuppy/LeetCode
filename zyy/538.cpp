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
    void convertBSTRecursive(TreeNode *root, int &sum) {
        if (root == NULL) {
            return;
        }

        convertBSTRecursive(root->right, sum);
        int rootVal(root->val);
        root->val += sum;
        sum += rootVal;
        convertBSTRecursive(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum(0);
        convertBSTRecursive(root, sum);
        return root;
    }
};
