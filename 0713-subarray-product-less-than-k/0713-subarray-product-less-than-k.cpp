class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int prod = 1;
        int res = 0;
        // sliding window approach
        int left = 0;
        int right = 0;
        int N = nums.size();
        while(right<N){
            prod*=nums[right];
            while(prod>=k){
                prod/=nums[left];
                left++;
            }
            res += right-left+1;
            right++;
        }
        return res;
    }
};