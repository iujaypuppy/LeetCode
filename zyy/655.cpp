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
    void printTree(TreeNode *root,
                   vector<vector<string>> &paper,
                   size_t beginRow,
                   size_t beginColumn, size_t columnWidth) {
        if (root == NULL) {
            return;
        }

        size_t midColumn(beginColumn + columnWidth / 2);
        paper[beginRow][midColumn] = to_string(root->val);
        printTree(root->left, paper, beginRow + 1, beginColumn, columnWidth / 2);
        printTree(root->right, paper, beginRow + 1, midColumn + 1, columnWidth / 2);
    }

    size_t getDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }

    vector<vector<string>> printTree(TreeNode* root) {
        size_t depth(getDepth(root));
        vector<vector<string>> ret(depth, vector<string>((1 << depth) - 1));
        printTree(root, ret, 0, 0, (1 << depth) - 1);
        return ret;
    }
};
