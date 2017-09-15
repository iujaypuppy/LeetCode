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
    int diameterOfBinaryTreeRecursive(TreeNode *root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return 0;
        }

        int leftDepth, rightDepth, leftD, rightD;
        leftD = diameterOfBinaryTreeRecursive(root->left, leftDepth);
        rightD = diameterOfBinaryTreeRecursive(root->right, rightDepth);
        depth = max(leftDepth, rightDepth) + 1;
        return max(leftD, max(rightD, leftDepth + rightDepth));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int depth;
        return diameterOfBinaryTreeRecursive(root, depth);
    }
};
