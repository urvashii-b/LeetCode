class Solution {
private:
    int solve(vector<int>& prices, int buy, int index, int n, vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        int profit = 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            profit = max(-prices[index]+solve(prices,0,index+1,n,dp), 
                         0+solve(prices,1,index+1,n,dp));
        }
        else{
            profit = max(prices[index]+solve(prices,1,index+1,n,dp), 
                         0+solve(prices,0,index+1,n,dp));
        }
        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        // canBuy --> 1 yes ---> 0 no
        // when you buy you add -prices[i] to the answer wherease when you sell you add prices[i]
        int n = prices.size(), canBuy = 1, index = 0;
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return solve(prices,canBuy,index,n,dp);
    }
};