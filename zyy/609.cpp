class Solution {
  public:
    void trim(string &str, string::iterator &start,
              /* the following are return values */
              string::iterator &left, string::iterator &right) {
        for (left = start;
             left != str.end() && isspace(*left);
             left++) {}

        right = left;

        while (right != str.end() && !isspace(*right)) {
            right++;
        }

        start = right;
    }

    class File {
      public:
        string path, content;
        File(const string &file) {
            string::const_iterator leftBracket, rightBracket;
            leftBracket = file.begin() + file.find('(');
            rightBracket = file.begin() + file.find(')');

            path = string(file.begin(), leftBracket);
            content = string(leftBracket + 1, rightBracket);
        }
    };

    void fileParser(string &dir, vector<File> &files) {
        string::iterator cur(dir.begin()), begin, end;
        trim(dir, cur, begin, end);
        string prefix;
        if (begin != end) {
            prefix = string(begin, end);
        }

        do {
            trim(dir, cur, begin, end);
            if (begin != end) {
                string file(prefix + "/" + string(begin, end));
                files.push_back(File(file));
            }
        } while (begin != end);
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<File> files;
        for (vector<string>::iterator i(paths.begin()); i != paths.end(); ++i) {
            fileParser(*i, files);
        }
        vector<vector<File>> groups;
        for (vector<File>::iterator i(files.begin()); i != files.end(); ++i) {
            bool groupExist(false);
            for (vector<vector<File>>::iterator j(groups.begin()); j != groups.end(); ++j) {
                if ((*j)[0].content == i->content) {
                    j->push_back(*i);
                    groupExist = true;
                    break;
                }
            }

            if (!groupExist) {
                groups.push_back(vector<File>(1, *i));
            }
        }

        vector<vector<string>> result;
        for (vector<vector<File>>::iterator i(groups.begin()); i != groups.end(); ++i) {
            if (i->size() < 2) {
                continue;
            }
            result.push_back(vector<string>());
            vector<string> &cur(*result.rbegin());
            for (vector<File>::iterator j(i->begin()); j != i->end(); ++j) {
                cur.push_back(j->path);
            }
        }

        return result;
    }
};
