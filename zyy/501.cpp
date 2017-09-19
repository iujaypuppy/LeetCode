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
    void updateModes(int &val, int &count, vector<int> &result, int &maxCount) {
        if (count == 0) {
            return;
        }
        if (count > maxCount) {
            result.clear();
            maxCount = count;
            result.push_back(val);
        } else if (count == maxCount) {
            result.push_back(val);
        }
    }
    void findModeRecursive(TreeNode *root, int &val, int &count,
                           vector<int> &result, int &maxCount) {
        if (root == NULL) {
            return;
        }

        findModeRecursive(root->left, val, count, result, maxCount);
        if (count == 0 || val != root->val) {
            updateModes(val, count, result, maxCount);
            val = root->val;
            count = 1;
        } else {
            count++;
        }
        findModeRecursive(root->right, val, count, result, maxCount);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int val, count(0), maxCount(0);
        findModeRecursive(root, val, count, result, maxCount);
        /* Update the final one */
        updateModes(val, count, result, maxCount);
        return result;
    }
};
