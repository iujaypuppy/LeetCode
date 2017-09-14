class Solution {
  public:
    class Score {
      private:
        int score;
        size_t index;
      public:
        Score(int s, size_t i): score(s), index(i) {}
        inline bool operator<(const Score &other) const { return score > other.score; }
        inline size_t position(void) const { return index; }
    };
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<Score> scores;
        for (vector<int>::iterator i(nums.begin()); i != nums.end(); i++) {
            scores.push_back(Score(*i, i - nums.begin()));
        }
        sort(scores.begin(), scores.end());

        vector<string> result(scores.size());
        for (vector<Score>::iterator i(scores.begin()); i != scores.end(); i++) {
            string position(to_string(i - scores.begin() + 1));
            if (position == "1") {
                position = "Gold Medal";
            } else if (position == "2") {
                position = "Silver Medal";
            } else if (position == "3") {
                position = "Bronze Medal";
            }
            result[i->position()] = position;
        }

        return result;
    }
};
