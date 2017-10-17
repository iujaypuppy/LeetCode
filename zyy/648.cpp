class Solution {
  public:
    class TrieNode {
      private:
        static const int WIDTH = 26;
        TrieNode *kids[WIDTH];
        bool root;
      public:
        inline bool isRoot(void) const { return root; }
        TrieNode(bool r = false): root(r) {
            for (int i(0); i < WIDTH; ++i) {
                kids[i] = NULL;
            }
        }

        void insert(const char *str) {
            if (isRoot()) {
                return;
            }
            if (str == NULL || str[0] == '\0') {
                root = true;
                return;
            }

            size_t index(str[0] - 'a');
            if (kids[index] == NULL) {
                kids[index] = new TrieNode(false);
            }
            kids[index]->insert(str + 1);
        }

        void insert(const string &str) {
            insert(str.c_str());
        }

        bool getRoot(const char *str, string &ret) {
            if (isRoot()) {
                ret = "";
                return true;
            }

            if (str == NULL || str[0] == '\0') {
                ret = "";
                return false;
            }

            size_t index(str[0] - 'a');
            if (kids[index] != NULL && kids[index]->getRoot(str + 1, ret)) {
                ret = string(1, str[0]) + ret;
                return true;
            }

            return false;
        }

        bool getRoot(const string &str, string &ret) {
            return getRoot(str.c_str(), ret);
        }
    };
    void trim(const string &str, const string::iterator &start,
              /* the following are return values */
              string::iterator &left, string::iterator &right) {
        for (left = start;
             left != str.end() && isspace(*left);
             left++) {}

        right = left;

        while (right != str.end() && !isspace(*right)) {
            right++;
        }
    }
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode root;
        for (vector<string>::iterator i(dict.begin()); i != dict.end(); ++i) {
            root.insert(*i);
        }

        string::iterator left, right, start(sentence.begin());
        string ret;
        do {
            trim(sentence, start, left, right);
            string rootWord, original(left, right);
            if (left >= right) {
                break;
            }
            if (ret != "") {
                ret += " ";
            }
            if (root.getRoot(original, rootWord)) {
                ret += rootWord;
            } else {
                ret += original;
            }
            start = right;
        } while(left < right);
        return ret;
    }
};
