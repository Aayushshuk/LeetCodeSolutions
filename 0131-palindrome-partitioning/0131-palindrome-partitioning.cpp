class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        findSolve(0, s, path, res);
        return res;
    }
    void findSolve(int index, string s, vector<string>& path, vector<vector<string>>& res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }
        for(int i= index; i<s.size();i++){
            if(Palindrome(s,index,i)){
                path.push_back(s.substr(index, i-index+1));
                findSolve(i+1,s, path,res);
                path.pop_back();
            }
        }
    }

    bool Palindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};