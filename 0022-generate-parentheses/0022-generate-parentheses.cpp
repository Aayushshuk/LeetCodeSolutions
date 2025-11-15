class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        solve(n,n,curr,res);
        return res;
    }
    void solve(int open, int close, string curr, vector<string>& res){
        if(close == 0 && open == 0){
            res.push_back(curr);
            return;
        }
        if(open>0){
            solve(open-1,close, curr + "(", res);
        }

        if(close > open){
            return solve(open, close-1, curr + ")",res);
        } 
    }
};