class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char>ch;
        for(int i=0; i<n;i++){
            while(!ch.empty() && k>0 && ((ch.top() -'0') > (num[i] -'0'))){
                ch.pop();
                k= k-1;
            }
            ch.push(num[i]);
        }
        while(k>0){
            ch.pop(); 
            k--;
        }
        if(ch.empty()) return "0";
        string res ="";
        while(!ch.empty()){
            res.push_back(ch.top());
            ch.pop();
        }
        while(res.size() >0 && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        if(res.empty()) return "0";
        return res;
    }
};