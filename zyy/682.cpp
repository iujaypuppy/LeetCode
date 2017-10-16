class Solution {
  public:
    int calPoints(vector<string>& ops) {
        vector<int> rounds;
        for (vector<string>::iterator i(ops.begin()); i != ops.end(); i++) {
            switch ((*i)[0]) {
                case '+':
                    rounds.push_back(*rounds.rbegin() + *(rounds.rbegin() + 1));
                    break;
                case 'C':
                    rounds.erase(rounds.end() - 1);
                    break;
                case 'D':
                    rounds.push_back(*rounds.rbegin() * 2);
                    break;
                default:
                    rounds.push_back(atoi(i->c_str()));
                    break;
            }
        }

        int sum(0);
        for (vector<int>::iterator i(rounds.begin()); i != rounds.end(); i++) {
            sum += *i;
        }

        return sum;
    }
};
