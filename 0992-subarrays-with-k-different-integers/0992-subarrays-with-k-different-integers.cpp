class Solution {
public:
    int atmostDiff(vector<int>& nums, int k){
        int left =0;
        int right =0;
        int count =0;
        unordered_map<int,int> mpp;
        while(right<nums.size()){
            mpp[nums[right]]++;
            while(mpp.size()>k)
            {
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left= left+1;
            }
            count += (right - left +1);
            right++;   
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (k <= 0) return 0;
        long long ans = atmostDiff(nums, k) - atmostDiff(nums, k-1);
        return (int)ans;
    }
};