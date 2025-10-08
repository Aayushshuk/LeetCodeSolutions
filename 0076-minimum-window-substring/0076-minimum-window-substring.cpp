class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        vector<int> need(128,0);

        for(char c: t) need[c]++;
        int required = t.size();
        int l=0,r=0;
        int bestLen =INT_MAX;
        int bestL=0;

        while(r <(int)s.size()){
            if(need[s[r]] > 0) required--;
            need[s[r]]--;
            r++;
            while (required == 0) {
                if (r - l < bestLen) {       // update smallest window
                    bestLen = r - l;
                    bestL = l;
                }

                need[s[l]]++;                // remove s[l] from window
                if (need[s[l]] > 0)          // we now miss a needed char
                    required++;
                l++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};