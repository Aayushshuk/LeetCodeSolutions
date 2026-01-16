class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        Reverse(nums, 0, nums.size()-1);
        Reverse(nums ,0, k-1);
        Reverse(nums, k, nums.size()-1);
    }
    void Reverse(vector<int>& nums, int start, int end){
        while(start<end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};