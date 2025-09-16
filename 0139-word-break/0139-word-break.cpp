class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = (int)s.size();
        // dp[start][end] = -1 unknown, 0 false, 1 true
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, s, dict, dp);
        
    }
private:
     bool solve(int start, int end, string &s,  unordered_set<string> &wd,vector<vector<int>> &dp) {
    int n = (int)s.size();

        // If we've segmented the whole string
        if (start == n) return true;

        // If end ran off the string, no more extension possible
        if (end == n) return false;

        int& memo = dp[start][end];
        if (memo != -1) return memo == 1;

        // Current substring is s[start..end] inclusive
        string word = s.substr(start, end - start + 1);

        // Option 1: cut here if word exists, then start a new segment at end+1
        if (wd.count(word) && solve(end + 1, end + 1, s, wd, dp)) {
            memo = 1;
            return true;
        }

        // Option 2: extend the end pointer
        bool ok = solve(start, end + 1, s, wd, dp);
        memo = ok ? 1 : 0;
        return ok;
    }
};