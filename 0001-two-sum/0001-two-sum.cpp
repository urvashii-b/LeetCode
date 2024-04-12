class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        1. BRUTE FORCE
        */
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int digit = target - nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]==digit){
                    return {i,j};
                }
            }
        }
        return {0,0};
    }
};