class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX, n = nums.size(), left = 0, sum = 0;
        for(int right = 0;right<n;right++){
            sum+=nums[right];
            while(sum>=target){
                mini = min(mini, right-left+1);
                sum-=nums[left++];
            }
        }
        return mini==INT_MAX? 0: mini;
    }
};