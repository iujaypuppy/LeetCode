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
    class Average {
      private:
        double sum;
        int count;
      public:
        Average(void): sum(0), count(0) {}
        void add(const double &number) {
            sum += number;
            count++;
        }

        double average(void) const { return sum / count; }
    };
    void averageOfLevelsRecursive(TreeNode *root, int level, vector<Average> &avgs) {
        if (root == NULL) {
            return;
        }
        while (level >= avgs.size()) {
            avgs.push_back(Average());
        }
        avgs[level].add(root->val);
        averageOfLevelsRecursive(root->left, level + 1, avgs);
        averageOfLevelsRecursive(root->right, level + 1, avgs);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<Average> avgs;
        averageOfLevelsRecursive(root, 0, avgs);
        vector<double> result;
        for (vector<Average>::iterator i(avgs.begin()); i != avgs.end(); i++) {
            result.push_back(i->average());
        }
        return result;
    }
};
