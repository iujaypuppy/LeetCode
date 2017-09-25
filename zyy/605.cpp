class Solution {
  public:
    /* Get a range which can be planted at every plot. */
    bool getRange(vector<int>::iterator &begin, vector<int>::iterator &end) {
        while (begin != end && *begin == 1) {
            begin++;
        }
        if (begin == end) {
            return false;
        }

        vector<int>::iterator e(begin + 1);
        while (e != end && *e == 0) {
            e++;
        }
        end = e;

        return true;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int>::iterator begin(flowerbed.begin()), end(flowerbed.end());
        while (getRange(begin, end)) {
            vector<int>::iterator nextBegin(end + 1), nextEnd(flowerbed.end());
            if (end == flowerbed.end()) {
                nextBegin = nextEnd;
            }
            if (begin != flowerbed.begin() && *(begin - 1) == 1) {
                begin++;
            }
            if (begin == end) {
                begin = nextBegin;
                end = nextEnd;
                continue;
            }

            if (end != flowerbed.end() && *end == 1) {
                end--;
            }
            if (begin == end) {
                begin = nextBegin;
                end = nextEnd;
                continue;
            }

            int num((end - begin - 1) / 2 + 1);
            n -= num;
            begin = nextBegin;
            end = nextEnd;
        }

        return n <= 0;
    }
};
