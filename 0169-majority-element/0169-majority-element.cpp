class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        unordered_map<int, int> ump;
        for(int i=0; i<n;i++){
            ump[nums[i]]++;
        }
        int r = n/2;
        for(auto x : ump){
            if(x.second > r){
                return x.first;
            }
        }
        return 0;
    }
};