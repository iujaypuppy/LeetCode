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
    int sumDownwards(TreeNode *root, int current, const int &sum) {
        if (root == NULL) {
            return 0;
        }

        current += root->val;
        return (current == sum ? 1 : 0) +
                sumDownwards(root->left, current, sum) +
                sumDownwards(root->right, current, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return NULL;
        }

        return sumDownwards(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
