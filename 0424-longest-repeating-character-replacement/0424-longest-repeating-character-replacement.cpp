class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int maxlen =0;
        int maxcount =0;
        int left =0;
        int right=0;
        while(right<s.size()){
            freq[s[right]-'A']++;
            maxcount = max(maxcount, freq[s[right]-'A']); 

            if((right-left+1) - maxcount > k){
                freq[s[left] - 'A']--;
                left++;   
            }
            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};