// class Solution {
// private:
//     int solve(int index, vector<int> &nums, vector<int> &dp){
//         if(index==0) return nums[0];
//         if(index<0) return 0;
//         if(dp[index]!=-1) return dp[index];
//         // pick
//         int pick = nums[index]+solve(index-2, nums, dp);
//         // not pick
//         int notpick = 0 + solve(index-1, nums, dp);
        
//         return dp[index] = max(pick, notpick);
//     }
// public:
//     int rob(vector<int>& nums) {
//         // no adjacent houses
//         int n = nums.size();
//         vector<int> dp(n+1, -1);
//         return solve(n-1, nums, dp);
//     }
// };

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         // no adjacent houses
//         int n = nums.size();
//         vector<int> dp(n+1, -1);
//         dp[0] = nums[0];
//         int neg = 0;
//         for(int i=1; i<n; i++){
//             int pick = nums[i];
//             if(i>1){
//                 pick += dp[i-2];
//             }
//             int notpick = 0 + dp[i-1];
//             dp[i] = max(pick, notpick);
//         }
//         return dp[n-1];
//     }
// };


class Solution {
public:
    int rob(vector<int>& nums) {
        // no adjacent houses
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i>1){
                pick += prev2;
            }
            int notpick = 0 + prev;
            int cur = max(pick, notpick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};