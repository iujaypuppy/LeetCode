class Solution {
  public:
    class Person {
      private:
        int h, k;
      public:
        pair<int, int> data;
        Person(const pair<int, int> &p):
                data(p), h(p.first), k(p.second) {}
        void insertFront(const Person &p) {
            if (p.h >= h) {
                k--;
                if (k < 0) {
                    throw "invalid queue";
                }
            }
        }
        inline bool operator<(const Person &other) {
            return k < other.k || (k == other.k && h < other.h);
        }
        inline bool canBeFirst(void) const { return k == 0; }
    };
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<Person> p;
        for (vector<pair<int, int>>::iterator i(people.begin());
             i != people.end(); i++) {
            p.push_back(Person(*i));
        }

        vector<pair<int, int>> ret;
        size_t size(p.size());
        for (size_t i(0); i < size; i++) {
            vector<Person>::iterator first(p.end());
            for (vector<Person>::iterator j(p.begin()); j != p.end(); j++) {
                if (first == p.end() || *j < *first) {
                    first = j;
                }
            }

            if (!first->canBeFirst()) {
                throw "invalid queue";
            }
            ret.push_back(first->data);
            for (vector<Person>::iterator j(p.begin()); j != p.end(); j++) {
                if (first != j) {
                    j->insertFront(*first);
                }
            }
            p.erase(first);
        }

        return ret;
    }
};
