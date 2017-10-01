class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);
        int current_row_index(1);
        while (current_row_index <= rowIndex) {
            row.insert(row.begin(), 1);
            for (size_t i(1); i < current_row_index; i++) {
                row[i] = row[i] + row[i + 1];
            }
            current_row_index++;
        }
        return row;
    }
};
