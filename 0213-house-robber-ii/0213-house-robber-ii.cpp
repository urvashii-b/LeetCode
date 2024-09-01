class Solution {
private:
    int solve(int index, vector<int>& nums, int start, vector<int> &dp){
        if(index==start) return nums[start];
        if(index<start) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick = nums[index]+solve(index-2,nums, start,dp);
        int notpick = 0+solve(index-1,nums, start,dp);
        return dp[index] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        /* 
        cannot contain first and last - circle property
        compute ans1 without first
        compute ans2 without last
        take max(first, last)
        */
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n+1, -1);
        int first = solve(n-1,nums,1, dp1);  // exclude first ele
        vector<int> dp2(n+1, -1);
        int last = solve(n-2,nums,0, dp2);   // exclude last ele
        return max(first,last);
    }
};