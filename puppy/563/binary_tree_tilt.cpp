/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class TiltTreeNode {
public:
    int val;
    int sum;
    int tilt;
    
    TiltTreeNode *left;
    TiltTreeNode *right;
    
    TiltTreeNode(int x) : val(x), sum(x), tilt(0), left(NULL), right(NULL) {}
    
    static TiltTreeNode* Construct(TreeNode* node) {
        if (node == NULL) {
            return NULL;
        }
        TiltTreeNode* new_node = new TiltTreeNode(node->val);
        new_node->left = Construct(node->left);
        new_node->right = Construct(node->right);
        return new_node;
    }
    
    int CalculateSum(TiltTreeNode* node) {
        if (node == NULL) {
            return 0; 
        }
        if (node->left != NULL) {
            node->sum += CalculateSum(node->left);
        }
        if (node->right != NULL) {
            node->sum += CalculateSum(node->right);
        }
        return node->sum;
    }
    
    void CalculateTilt(TiltTreeNode* node) {
        if (node == NULL) {
            return;
        }
        int left_sum = (node->left == NULL) ? 0 : node->left->sum;
        int right_sum = (node->right == NULL) ? 0 : node->right->sum;
        node->tilt = abs(left_sum - right_sum);
        CalculateTilt(node->left);
        CalculateTilt(node->right);
    }
    
    int SumTilt(TiltTreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int sum(node->tilt);
        sum += SumTilt(node->left);
        sum += SumTilt(node->right);
        return sum;
    }
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        int res(0);
        TiltTreeNode* tilt_root = TiltTreeNode::Construct(root);
        if (tilt_root) {
            tilt_root->CalculateSum(tilt_root);
            tilt_root->CalculateTilt(tilt_root);
            res = tilt_root->SumTilt(tilt_root);
        }
        
        return res;
    }
};


