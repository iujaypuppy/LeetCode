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
    int pathSum(TreeNode* root, int sum) {
        int count(0);
        vector<int> preVals;
        pathSum(root, sum, count, preVals);   
        return count;
    }
    
    void pathSum(TreeNode* node, int sum, int& count, vector<int> preVals) {
        if (node == NULL) {
            return;
        }
        
        preVals.push_back(node->val);
        
        count += findPath(preVals, sum);
        
        pathSum(node->left, sum, count, preVals);
        pathSum(node->right, sum, count, preVals);
    }
    
    int findPath(vector<int> nums, int sum) {
        int res(0);
        for (int i(nums.size() - 1); i >= 0; i--) {
            if (sum == nums[i]) {
                res++;
            }
            sum -= nums[i];
        }
        return res;
    }
};
