class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans;
        for(int i=0; i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto x : mpp){
            if(x.second%2 == 1){
                ans = x.first;
            }
        }
        return ans;
    }
};