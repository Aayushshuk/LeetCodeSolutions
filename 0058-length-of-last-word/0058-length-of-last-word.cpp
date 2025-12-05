class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        int length=0;
        while(s[i] == ' ' && i>0){
            i--;
        }
        while(i>=0 && s[i] != ' '){
            length++;
            i--;
        }
        return length;
    }
};