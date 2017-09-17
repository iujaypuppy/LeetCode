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
    int getMinimumDifference(TreeNode* root) {
        vector<int> vals;
        get_vals(root, vals);
        sort(vals.begin(), vals.end());
        
        int res = *(vals.end() - 1) - *(vals.begin());
        for(vector<int>::iterator iter(vals.begin() + 1); iter != vals.end(); iter++) {
            int diff = *iter - *(iter - 1);
            res = min(res, diff);
        }
        return res;
    }
    
    void get_vals(TreeNode* root, vector<int>& vals) {
        if (root == NULL) {
            return;
        }
        vals.push_back(root->val);
        get_vals(root->left, vals);
        get_vals(root->right, vals);
    }
};
