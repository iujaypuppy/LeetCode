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
    TreeNode* sortedArrayIteratorsToBST(vector<int>::iterator begin,
                                        vector<int>::iterator end) {
        if (begin == end) {
            return NULL;
        }

        size_t size(end - begin);
        size_t right((size - 1) / 2);
        size_t left(size - right - 1);
        TreeNode *root(new TreeNode(*(begin + left)));
        root->left = sortedArrayIteratorsToBST(begin, begin + left);
        root->right = sortedArrayIteratorsToBST(end - right, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayIteratorsToBST(nums.begin(), nums.end());
    }
};
