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
    void findSecondMinimumValueRecursive(TreeNode *root,
                                         int &min, int &secondMin) {
        if (root == NULL) {
            return;
        }

        if (min < 0 || root->val < min) {
            secondMin = min;
            min = root->val;
        } else if (root->val > min
                   && (secondMin < 0 || root->val < secondMin)) {
            secondMin = root->val;
        }

        
        findSecondMinimumValueRecursive(root->left, min, secondMin);
        findSecondMinimumValueRecursive(root->right, min, secondMin);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int min(-1), secondMin(-1);
        findSecondMinimumValueRecursive(root, min, secondMin);
        return secondMin;
    }
};
