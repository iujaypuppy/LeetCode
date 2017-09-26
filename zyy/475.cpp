class Solution {
  public:
    int dichonomy(vector<int> &houses, int n, bool isLeft) {
        int l(-1), r((int)houses.size());
        while (r - l > 1) {
            size_t m((l + r) / 2);

            if (houses[m] == n) {
                return n;
            }
            if (houses[m] < n) {
                l = m;
                continue;
            }
            r = m;
        }

        if (isLeft && (size_t)r != houses.size()) {
            return houses[(size_t)r];
        }

        if (!isLeft && l != -1) {
            return houses[(size_t)l];
        }

        return n;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.empty() || heaters.empty()) {
            return 0;
        }

        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        int ret(0);
        for (vector<int>::iterator heater(heaters.begin()); heater != heaters.end(); heater++) {
            int left(*houses.begin()), right(*(houses.end() - 1));
            if (heater != heaters.begin()) {
                left = (*heater + *(heater - 1)) / 2 + (*heater + *(heater - 1)) % 2;
            }
            if (heater != heaters.end() - 1) {
                right = (*heater + *(heater + 1)) / 2;
            }

            left = dichonomy(houses, left, true);
            if (left > *(houses.end() - 1) || left < *houses.begin()) {
                left = *heater;
            }
            right = dichonomy(houses, right, false);
            if (right > *(houses.end() - 1) || right < *houses.begin()) {
                right = *heater;
            }
            
            ret = max(ret, *heater - left);
            ret = max(ret, right - *heater);
        }

        return ret;
    }
};
