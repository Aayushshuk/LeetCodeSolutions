class Solution {
public:
    void LetterCombination(int i,string digits,string s, unordered_map<char,string> mpp, 
    vector<string>& Result){
        int n =digits.length();
        if(n==0){
            return;
        }
        if(i==n){
            Result.push_back(s);
            return;
        }
        char letter = digits[i];
        string Letter = mpp[letter];
        for(char ch: Letter){
            s.push_back(ch);
            LetterCombination(i+1, digits, s, mpp, Result);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        vector<string> Result;
        string s;
        LetterCombination(0, digits, s,mpp,Result);
        return Result;
    }
};