class Solution {
public:
    bool ispalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> out;
        solverec(0, s, out, ans);
        return ans;
    }

    void solverec(int index, string s, vector<string>& out, vector<vector<string>>& ans) {
        if (index == s.size()) {
            ans.push_back(out);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (ispalindrome(s, index, i)) {
                out.push_back(s.substr(index, i - index + 1));
                solverec(i + 1, s, out, ans);
                out.pop_back();
            }
        }
        return;
    }
};
