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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> levels_sums;
        vector<double> levels_nums;
        calculate_sum(root, levels_sums, levels_nums, 0);
        return calculate_average(levels_sums, levels_nums);
    }
    void calculate_sum(TreeNode* node, vector<double>& levels_sums, vector<double>& levels_nums, int level) {
        if (node == NULL) {
            return;
        }
        
        if (levels_sums.size() < level + 1) {
            levels_sums.push_back(node->val);
            levels_nums.push_back(1);
        } else {
            levels_sums[level] += node->val;
            levels_nums[level] += 1;
        }
        
        calculate_sum(node->left, levels_sums, levels_nums, level + 1);
        calculate_sum(node->right, levels_sums, levels_nums, level + 1);
    }
    
    vector<double> calculate_average(vector<double>& sums, vector<double>& nums) {
        vector<double> res;
        int size = sums.size();
        for (int i = 0; i < size; i++) {
            res.push_back(sums[i] / nums[i]);
        }
        return res;
    }
 };
