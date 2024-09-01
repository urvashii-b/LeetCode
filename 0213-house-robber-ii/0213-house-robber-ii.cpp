// class Solution {
// private:
//     int solve(int index, vector<int>& nums, int start, vector<int> &dp){
//         if(index==start) return nums[start];
//         if(index<start) return 0;
//         if(dp[index]!=-1) return dp[index];
//         int pick = nums[index]+solve(index-2,nums, start,dp);
//         int notpick = 0+solve(index-1,nums, start,dp);
//         return dp[index] = max(pick,notpick);
//     }
// public:
//     int rob(vector<int>& nums) {
//         /* 
//         cannot contain first and last - circle property
//         compute ans1 without first
//         compute ans2 without last
//         take max(first, last)
//         */
//         int n = nums.size();
//         if(n==1) return nums[0];
//         vector<int> dp1(n+1, -1);
//         int first = solve(n-1,nums,1, dp1);  // exclude first ele
//         vector<int> dp2(n+1, -1);
//         int last = solve(n-2,nums,0, dp2);   // exclude last ele
//         return max(first,last);
//     }
// };

// class Solution {
// private:
//     int solveTabulation(int end, vector<int>& nums, int start){
//         vector<int> dp(nums.size(), 0);
//         dp[start] = nums[start];
//         for(int i=start+1; i<=end; i++){
//             int pick = nums[i] + (i > start+1? dp[i-2]: 0);
//             int notpick = 0 + dp[i-1];
//             dp[i]=max(pick,notpick);
//         }
//         return dp[end];
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return nums[0];
        
//         int first = solveTabulation(n-1,nums,1);
//         int second = solveTabulation(n-2,nums,0);
        
//         return max(first,second);
//     }
// };

class Solution {
private:
    int solve(vector<int>& nums){
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        for(int i=1; i<n; i++){
            int pick = nums[i] + (i>1? prev2: 0);
            int notpick = 0 + prev;
            int cur = max(pick,notpick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1(n), temp2(n);
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1), solve(temp2));
    }
};