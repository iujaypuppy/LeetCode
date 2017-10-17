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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Find path for p, q. E.g. 2->"L", 8->"R", 4->"LR"
        string pPath(""), qPath("");
        findPath(root, p, pPath, q, qPath, "");
        
        // Find common path. E.g, (2, 8)->"", (2, 4)->"L"
        string commonPath("");
        size_t pLen(pPath.size()), qLen(qPath.size());
        for (size_t i(0); i < pLen && i < qLen; i++) {
            if (pPath[i] == qPath[i]) {
                commonPath += pPath[i];
            } else {
                break;
            }
        }
        
        // Find node by path
        return findNodeByPath(root, commonPath, 0);
    }
    
    TreeNode* findNodeByPath(TreeNode* node, string path, size_t index) {
        if (index >= path.size()) {
            return node;
        }
        if (path[index] == 'L') {
            return findNodeByPath(node->left, path, index + 1);
        } else {
            return findNodeByPath(node->right, path, index + 1);
        }
    }
    
    void findPath(TreeNode* node, TreeNode* p, string& pPath, TreeNode* q, string& qPath, string current) {
        if (node == NULL) {
            return;
        }
        if (!pPath.empty() && !qPath.empty()) {
            return;
        }
        if (node == p) {
            pPath = current;
        }
        if (node == q) {
            qPath = current;
        }
        findPath(node->left, p, pPath, q, qPath, current + 'L');
        findPath(node->right, p, pPath, q, qPath, current + 'R');
    }
};
