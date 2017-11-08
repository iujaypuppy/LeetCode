class Solution {
  public:
    int countClass(int p, int b, int n) {
        /* p*k + b >= 1 -> k >= (1 - b) / p */
        int k0((1 <= b) ? 0 : 1);
        /* p * k + b <= r -> k <= (r - b) / p */
        int k1(n < b ? -1 : (n - b) / p);
        return max(k1 - k0 + 1, 0);
    }
    int getMin(int p, int b, int n) {
        int k((1 <= b) ? 0 : 1);
        int i(p * k + b);
        return i > n ? -1 : i;
    }
    int getMax(int p, int b, int n) {
        int k((n - b) / p);
        int i(p * k + b);
        return i < 1 ? -1 : i;
    }
    bool isClass(int p, int b, int n) {
        return (n - b) % p == 0;
    }
    int lastRemaining(int n) {
        /*
          Represent all numbers as: p*k + b.
          At the beginning, p == 2, and b can be 0 or 1, which means,
          there are two kinds of numbers: 2k class and (2k + 1) class. So, now check the
          last number of n, if it is 2k, then the rest is (2k + 1)-class.
          After that, we can further know that, all numbers can be divided into
          4k-class and (4k + 2)-class (if 2k-class is left) or
          (4k + 1)-class and (4k + 3)-class (if (2k + 1)-class is left in the last round).
          Likewise, we can repeat until there is only one number left in two different classes.
        */
        int p(2), b0(0), b1(1);
        bool leftToRight(true);
        while (countClass(p, b0, n) + countClass(p, b1, n) > 1) {
            int b;
            if (leftToRight) {
                int k0(getMin(p, b0, n)), k1(getMin(p, b1, n));
                if (k0 < k1) {
                    b = b1;
                } else {
                    b = b0;
                }
            } else {
                int k0(getMax(p, b0, n)), k1(getMax(p, b1, n));
                if (k0 > k1) {
                    b = b1;
                } else {
                    b = b0;
                }
            }
            b0 = b;
            b1 = b + p;
            p *= 2;
            leftToRight = !leftToRight;
        }

        return max(getMin(p, b0, n), getMin(p, b1, n));
    }
};
