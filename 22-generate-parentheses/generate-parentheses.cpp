class Solution {
public:
    void generate(string s, int opening, int closing, int n, vector<string>& res) {
        if (closing == n) {
            res.push_back(s);
            return;
        }
        if (opening < n)
            generate(s + '(', opening + 1, closing, n, res);
        if (closing < opening)
            generate(s + ')', opening, closing + 1, n, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("", 0, 0, n, res);
        return res;
    }
};
