class MapSum {
  public:
    /** Initialize your data structure here. */
    class TrieNode {
      private:
        static const int WIDTH = 256;
        TrieNode *kids[WIDTH];
        int value;
      public:
        TrieNode(int v = 0): value(v) {
            for (int i(0); i < WIDTH; ++i) {
                kids[i] = NULL;
            }
        }

        void insert(const char *str, int v) {
            if (str == NULL || str[0] == '\0') {
                value = v;
                return;
            }

            if (kids[(size_t)str[0]] == NULL) {
                kids[(size_t)str[0]] = new TrieNode();
            }
            kids[(size_t)str[0]]->insert(str + 1, v);
        }

        void insert(const string &str, int v) {
            insert(str.c_str(), v);
        }

        int getSum(void) const {
            int sum(value);
            for (int i(0); i < WIDTH; ++i) {
                if (kids[i] != NULL) {
                    sum += kids[i]->getSum();
                }
            }
            return sum;
        }

        TrieNode *getNode(const char *prefix) {
            if (prefix == NULL || prefix[0] == '\0') {
                return this;
            }

            if (kids[(size_t)prefix[0]] == NULL) {
                return NULL;
            }

            return kids[(size_t)prefix[0]]->getNode(prefix + 1);
        }

        TrieNode *getNode(const string &prefix) {
            return getNode(prefix.c_str());
        }
    } *root;
    MapSum(): root(new TrieNode()) {
    }
    
    void insert(string key, int val) {
        root->insert(key, val);
    }

    int sum(string prefix) {
        TrieNode *prefixRoot(root->getNode(prefix));
        return prefixRoot == NULL ? 0 : prefixRoot->getSum();
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
