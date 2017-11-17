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
    TreeNode *findMax(TreeNode *root) {
        while (root != NULL && root->right != NULL) {
            root = root->right;
        }
        return root;
    }
    TreeNode *findMin(TreeNode *root) {
        while (root != NULL && root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left != NULL) {
                TreeNode *stand(findMax(root->left));
                root->val = stand->val;
                root->left = deleteNode(root->left, stand->val);
            } else if (root->right != NULL) {
                TreeNode *stand(findMin(root->right));
                root->val = stand->val;
                root->right = deleteNode(root->right, stand->val);
            } else {
                root = NULL;
            }
        }

        return root;
    }
};
