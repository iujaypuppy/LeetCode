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
    int findAllTreeSum(TreeNode *root, vector<int> &sums) {
        if (root == NULL) {
            return 0;
        }
        int sum(root->val +
                findAllTreeSum(root->left, sums) +
                findAllTreeSum(root->right, sums));
        sums.push_back(sum);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> all;
        findAllTreeSum(root, all);

        vector<int> ret;
        int freq(0), max(0);
        sort(all.begin(), all.end());
        for (vector<int>::iterator i(all.begin()); i != all.end(); ++i) {
            if (i == all.begin() || *i == *(i - 1)) {
                freq++;
                continue;
            }
            if (freq >= max) {
                if (freq > max) {
                    max = freq;
                    ret.clear();
                }
                ret.push_back(*(i - 1));
            }
            freq = 1;
        }
        if (freq >= max && !all.empty()) {
            if (freq > max) {
                ret.clear();
            }
            ret.push_back(*(all.end() - 1));
        }

        return ret;
    }
};
