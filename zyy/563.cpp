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
    int findTiltRecursive(TreeNode *root, int &sum) {
        sum = 0;
        if (root == NULL) {
            return 0;
        }

        int tilt(0), lSum, rSum;
        tilt += findTiltRecursive(root->left, lSum);
        tilt += findTiltRecursive(root->right, rSum);
        tilt += rSum > lSum ? rSum - lSum : lSum - rSum;
        sum = root->val + lSum + rSum;

        return tilt;
    }
    int findTilt(TreeNode *root) {
        int sum;
        return findTiltRecursive(root, sum);
    }
};
