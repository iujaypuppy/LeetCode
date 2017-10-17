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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Create the tree with its size equals to n
        TreeNode* root = createHeightBalancedBST(nums.size());
        
        // Inorder tranversal to assign corresponding value to each node
        int index(0);
        SetBSTVal(root, nums, index);
        
        return root;
    }
    
    void SetBSTVal(TreeNode* node, vector<int>& nums, int& index) {
        if (node == NULL) {
            return;
        }
        
        SetBSTVal(node->left, nums, index);
        
        node->val = nums[index];
        index++;
        
        SetBSTVal(node->right, nums, index);
    }
    
    TreeNode* createHeightBalancedBST(int n) {
        if (n == 0) {
            return NULL;
        }
        
        static const int defaultVal = 0;
        TreeNode* root = new TreeNode(defaultVal);
        n--;
        
        queue<TreeNode*> leaveNodes;
        leaveNodes.push(root);
        while (n > 1) {
            TreeNode* cur = leaveNodes.front();
            
            TreeNode* left = new TreeNode(defaultVal);
            cur->left = left;
            
            TreeNode* right = new TreeNode(defaultVal);
            cur->right = right;
            
            leaveNodes.pop();
            leaveNodes.push(left);
            leaveNodes.push(right);
            
            n -= 2;
        }
        
        if (n == 1) {
            TreeNode* cur = leaveNodes.front();
            cur->left = new TreeNode(defaultVal);
        }
        
        return root;
    }
};
