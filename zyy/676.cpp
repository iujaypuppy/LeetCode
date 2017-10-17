class MagicDictionary {
  public:
    /** Initialize your data structure here. */
    class TrieNode {
      private:
        static const int WIDTH = 256;
        TrieNode *kids[WIDTH];
        bool word;
      public:
        inline bool isWord(void) const { return word; }
        TrieNode(bool w = false): word(w) {
            for (int i(0); i < WIDTH; ++i) {
                kids[i] = NULL;
            }
        }

        void insert(const char *str) {
            if (str == NULL || str[0] == '\0') {
                word = true;
                return;
            }

            if (kids[(size_t)str[0]] == NULL) {
                kids[(size_t)str[0]] = new TrieNode(false);
            }
            kids[(size_t)str[0]]->insert(str + 1);
        }

        void insert(const string &str) {
            insert(str.c_str());
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
        bool search(const char *str) {
            if (str == NULL || str[0] == '\0') {
                return false;
            }
            /* general match case */
            if (kids[(size_t)str[0]] != NULL) {
                if (kids[(size_t)str[0]]->search(str + 1)) {
                    return true;
                }
            }
            /* substitution case */
            for (int i(0); i < WIDTH; i++) {
                if (kids[i] != NULL && (char)i != str[0]) {
                    TrieNode *node = kids[i]->getNode(str + 1);
                    if (node != NULL && node->isWord()) {
                        return true;
                    }
                }
            }
            return false;
        }
        bool search(const string &str) {
            return search(str.c_str());
        }
    } *root;
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        root = new TrieNode();
        for (vector<string>::iterator i(dict.begin()); i != dict.end(); ++i) {
            root->insert(*i);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return root->search(word);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
