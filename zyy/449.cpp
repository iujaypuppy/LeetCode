/**
 * Definition for a binary tree node.
 *
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        string left(serialize(root->left)), right(serialize(root->right)),
                result(to_string(root->val));
        if (right != "") {
            return result + "(" + left + ")(" + right + ")";
        }
        if (left != "") {
            return result + "(" + left + ")";
        }

        return result;
    }

    static size_t findMatchBracket(string &s, size_t l) {
        int count(1);
        for (size_t i(l + 1); i < s.length(); i++) {
            if (s[i] == '(') {
                count++;
                continue;
            }
            if (s[i] == ')') {
                count--;
                if (count == 0) {
                    return i;
                }
            }
        }
        return l;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        size_t leftBracket(data.find('(')), rightBracket,
                length(data.length());
        if (leftBracket == string::npos) {
            leftBracket = length;
            rightBracket = length;
        } else {
            rightBracket = findMatchBracket(data, leftBracket);
        }
        TreeNode *root(new TreeNode(atoi(data.substr(0, leftBracket).c_str())));
        if (leftBracket != rightBracket) {
            root->left = deserialize(data.substr(leftBracket + 1,
                                                 rightBracket - leftBracket - 1));
        }
        if (rightBracket + 2 < length) {
            root->right = deserialize(data.substr(rightBracket + 2, length - rightBracket - 3));
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
