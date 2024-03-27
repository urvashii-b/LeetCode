class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // sliding window approach
        if(k<=1) return 0;
        int prod = 1, res = 0, left = 0, right = 0, N = nums.size();
        while(right<N){
            prod*=nums[right];
            while(prod>=k){
                prod/=nums[left++];
            }
            res += right-left+1;
            right++;
        }
        return res;
    }
};