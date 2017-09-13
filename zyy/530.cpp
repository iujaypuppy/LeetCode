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
    TreeNode *findMin(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode *result(root);
        while (result->left != NULL) {
            result = result->left;
        }

        return result;
    }
    TreeNode *findMax(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode *result(root);
        while (result->right != NULL) {
            result = result->right;
        }

        return result;
    }
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }

        TreeNode *prev(findMax(root->left)), *next(findMin(root->right));
        int min(-1);
        if (prev != NULL && (min == -1 || root->val - prev->val < min)) {
            min = root->val - prev->val;
        }
        if (next != NULL && (min == -1 || next->val - root->val < min)) {
            min = next->val - root->val;
        }

        int left(getMinimumDifference(root->left)), right(getMinimumDifference(root->right));
        if (left != -1 && (min == -1 || left < min)) {
            min = left;
        }
        if (right != -1 && (min == -1 || right < min)) {
            min = right;
        }

        return min;
    }
};
