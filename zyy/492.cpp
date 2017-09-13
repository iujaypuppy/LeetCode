class Solution {
  public:
    vector<int> constructRectangle(int area) {
        int L((int)sqrt(area)), W((int)sqrt(area));

        while (true) {
            int product(L * W);
            if (product < area) {
                L++;
                int complement(area / L);
                if (W > complement) {
                    W = complement;
                }
                continue;
            }

            if (product > area) {
                W--;
                int complement(area / W);
                if (L < complement) {
                    L = complement;
                }
                continue;
            }

            vector<int> result;
            result.push_back(L);
            result.push_back(W);
            return result;
        }

        return vector<int>();
    }
};
