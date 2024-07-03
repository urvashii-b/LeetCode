class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        for(int l = 0, r = n-4; l<4;l++, r++){
            mini = min(mini, nums[r]-nums[l]);
        }
        return mini;
    }
};