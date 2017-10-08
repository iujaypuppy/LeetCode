class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        size_t len(flowerbed.size());
        for (size_t i(0); i < len && n > 0; i++) {
            if (flowerbed[i] == 0) {
                bool before = (i == 0) || (flowerbed[i - 1] == 0);
                bool next = (i == len - 1) || (flowerbed[i + 1] == 0);
                n -= (before && next) ? 1 : 0;
                flowerbed[i] = (before && next) ? 1 : 0;
            }
        }
        return n == 0;
    }
};
