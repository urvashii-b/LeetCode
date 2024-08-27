class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // vector<int> dp(n+1,0);
        // for(int i=2;i<=n;i++){
        //     dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        // }
        // return dp[n];
        int n = cost.size();
        int prev1 = 0, prev2 = 0;
        for(int i=2;i<=n;i++){
            int cur=min(prev1+cost[i-1],prev2+cost[i-2]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};