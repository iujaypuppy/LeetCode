class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0) {
            return res;
        }
        
        res.push_back(vector<int>(1, 1));
        if (numRows == 1) {
            return res;
        }
        
        int i(0);
        while (i < numRows - 1) {
            vector<int> current;
            
            current.push_back(1);
            for (size_t j(0); j < (res[i].size() - 1); j++) {
                current.push_back(res[i][j] + res[i][j + 1]);
            }
            current.push_back(1);
            
            res.push_back(current);
            i++;
        }
        return res;
    }
};
