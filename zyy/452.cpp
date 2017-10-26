class Solution {
  public:
    class Balloon {
      private:
        int s, e;
      public:
        bool burst;
        Balloon(const pair<int, int> &p):
                s(p.first), e(p.second), burst(false) {}
        int start() const { return s; }
        int end() const { return e; }
    };

    class Point {
      private:
        Balloon *b;
        bool s;
      public:
        Point(Balloon &balloon, bool start): b(&balloon), s(start) {}
        void invalidate(void) { b->burst = true; }
        bool isValid(void) const { return !b->burst; }
        bool isStart(void) const { return s; }
        int value(void) const { return s ? b->start() : b->end(); }
        bool operator<(const Point &other) const {
            return value() < other.value() ||
                             (value() == other.value() && s);
        }
    };

    int findMinArrowShots(vector<pair<int, int>>& points) {
        vector<Balloon> balloons;
        for (vector<pair<int, int>>::iterator i(points.begin()); i != points.end(); i++) {
            balloons.push_back(Balloon(*i));
        }

        vector<Point> p;
        for (vector<Balloon>::iterator i(balloons.begin()); i != balloons.end(); i++) {
            p.push_back(Point(*i, true));
            p.push_back(Point(*i, false));
        }

        sort(p.begin(), p.end());

        int count(0);
        vector<Point> entered;
        for (vector<Point>::iterator i(p.begin()); i != p.end(); i++) {
            if (!i->isValid()) {
                continue;
            }

            if (i->isStart()) {
                entered.push_back(*i);
                continue;
            }

            count++;
            for (vector<Point>::iterator i(entered.begin()); i != entered.end(); i++) {
                i->invalidate();
            }
            entered.clear();
        }

        return count;
    }
};
