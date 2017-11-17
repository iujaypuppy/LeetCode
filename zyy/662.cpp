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
    /*
      pos means the position in the same level,
      minPos means the minimum position number in a level.
     */
    void widthOfBinaryTree(TreeNode *root, int level, int pos,
                           vector<int> &minPos, vector<int> &maxPos) {
        if (root == NULL) {
            return;
        }

        if (level >= minPos.size()) {
            minPos.resize(level + 1, 1 << level);
            minPos[level] = pos;
        }
        if (level >= maxPos.size()) {
            maxPos.resize(level + 1, -1);
            maxPos[level] = pos;
        }
        minPos[level] = min(minPos[level], pos);
        maxPos[level] = max(maxPos[level], pos);
        widthOfBinaryTree(root->left, level + 1, pos * 2, minPos, maxPos);
        widthOfBinaryTree(root->right, level + 1, pos * 2 + 1, minPos, maxPos);
    }
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> minPos, maxPos;
        widthOfBinaryTree(root, 0, 0, minPos, maxPos);
        int ret(0);
        for (size_t i(0); i < minPos.size(); i++) {
            ret = max(ret, maxPos[i] - minPos[i] + 1);
        }
        return ret;
    }
};
