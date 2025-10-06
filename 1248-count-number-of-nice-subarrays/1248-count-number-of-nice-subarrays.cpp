class Solution {
public:
    int AtmostSum(vector<int>& nums, int k){
        if(k<0) return 0;
        int left =0;
        int right =0;
        int sum=0;
        int count =0;
        while(right<nums.size()){
            sum += (nums[right]%2);
            while(sum>k){
                sum -= (nums[left]%2);
                left= left+1;
            }
            count += (right - left +1);
            right =right+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return AtmostSum(nums, k)-AtmostSum(nums,k-1);
    }
};