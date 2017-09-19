class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int i(0); i <= rowIndex; i++) {
            row.resize(i + 1);
            row[0] = row[i] = 1;
            for (int j(i - 1); j >= 1; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};
