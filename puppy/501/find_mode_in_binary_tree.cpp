/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> vals;
        get_vals(root, vals);
        
        vector<int> res;
        res = find_mode(vals);
        return res;
    }
    
    vector<int> find_mode(vector<int> vals) {
        vector<int> res;
        if (vals.size() == 0) {
            return res;
        }
        if (vals.size() == 1) {
            res.push_back(vals[0]);
            return res;
        }
        
        // count frequence of the most frequently occurred element
        int max_times(1), j(0), len(vals.size());
        for (size_t i(1); i < len; i++) {
            if (vals[i] != vals[j]) {
                max_times = (max_times > i - j) ? max_times : (i - j);
                j = i;
            } 
        }
        max_times = (max_times > len - j) ? max_times : (len - j);
        
        // collect the val whose's frequence equals to the max_times
        j = 0;
        for (size_t i(1); i < len; i++) {
            if (vals[i] != vals[j]) {
                if (i - j == max_times) {
                    res.push_back(vals[j]);
                }
                j = i;
            }
        }
        if (len - j == max_times) {
            res.push_back(vals[j]);
        }
        
        return res;
    }
    
    void get_vals(TreeNode* node, vector<int>& res) {
        if (node == NULL) {
            return;
        }     
        get_vals(node->left, res);
        res.push_back(node->val);
        get_vals(node->right, res);
    }
};
