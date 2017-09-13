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
    void traverse(TreeNode *root, vector<int> &arr) {
        if (root == NULL) {
            return;
        }

        traverse(root->left, arr);
        arr.push_back(root->val);
        traverse(root->right, arr);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        traverse(root, arr);
        if (arr.empty()) {
            return false;
        }

        vector<int>::iterator left(arr.begin()), right(arr.end() - 1);
        while (left < right) {
            int sum(*left + *right);
            if (sum < k) {
                left++;
                continue;
            }
            if (sum > k) {
                right--;
                continue;
            }
            return true;
        }

        return false;
    }
};
