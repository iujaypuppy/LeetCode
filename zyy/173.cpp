/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  private:
    stack<TreeNode *> leftMostPath;
  public:
    BSTIterator(TreeNode *root) {
        getLeftMostPath(root);
    }

    void getLeftMostPath(TreeNode *root) {
        while (root != NULL) {
            leftMostPath.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !leftMostPath.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur(leftMostPath.top());
        leftMostPath.pop();
        getLeftMostPath(cur->right);
        return cur->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
