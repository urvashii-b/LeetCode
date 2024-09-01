// class Solution {
// private:
//     int solve(vector<int>& nums, int n, int k, int index, vector<int> &dp){
//         if(index==n){
//             return 0;
//         }
//         if(dp[index]!=-1) return dp[index];
//         int len = 0, maxAns = INT_MIN, maxi = INT_MIN;
//         for(int j=index; j<min(index+k,n); j++){
//             len++;
//             maxi = max(maxi, nums[j]);
//             int sum = (len*maxi) + solve(nums,n,k,j+1, dp);
//             maxAns = max(maxAns, sum);
//         }
//         return dp[index] = maxAns;
//     }
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> dp(n+1, -1);
//         return solve(arr,n,k,0, dp);
//     }
// };

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        dp[n]=0;
        for(int index=n-1; index>=0; index--){
            int len = 0, maxAns = INT_MIN, maxi = INT_MIN;
            for(int j=index; j<min(index+k,n); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (len*maxi) + dp[j+1];
                maxAns = max(maxAns, sum);
            }
            dp[index] = maxAns;
        }
        return dp[0];
    }
};