// class Solution {
// private:
//     int solve(vector<int>& prices, int buy, int index, int n, vector<vector<int>> &dp){
//         if(index==n){
//             return 0;
//         }
//         int profit = 0;
//         if(dp[index][buy]!=-1) return dp[index][buy];
//         if(buy){
//             profit = max(-prices[index]+solve(prices,0,index+1,n,dp), 
//                          0+solve(prices,1,index+1,n,dp));
//         }
//         else{
//             profit = max(prices[index]+solve(prices,1,index+1,n,dp), 
//                          0+solve(prices,0,index+1,n,dp));
//         }
//         return dp[index][buy] = profit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         // canBuy --> 1 yes ---> 0 no
//         // when you buy you add -prices[i] to the answer wherease when you sell you add prices[i]
//         int n = prices.size(), canBuy = 1, index = 0;
//         vector<vector<int>> dp(n+1,vector<int> (2,-1));
//         return solve(prices,canBuy,index,n,dp);
//     }
// };


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // canBuy --> 1 yes ---> 0 no
//         // when you buy you add -prices[i] to the answer wherease when you sell you add prices[i]
//         int n = prices.size(), canBuy = 1;
//         vector<vector<int>> dp(n+1,vector<int> (2,-1));
//         dp[n][0]=dp[n][1]=0;
//         for(int index=n-1; index>=0; index--){
//             for(int canBuy = 0; canBuy<=1; canBuy++){
//                 int profit = 0;
//                 if(dp[index][canBuy]!=-1) return dp[index][canBuy];
//                 if(canBuy==1){
//                     profit = max(-prices[index]+dp[index+1][0], 
//                                  0+dp[index+1][1]);
//                 }
//                 if(canBuy==0){
//                     profit = max(prices[index]+dp[index+1][1], 
//                                  0+dp[index+1][0]);
//                 }
//                 dp[index][canBuy] = profit;
//             }
//         }
//         return dp[0][1];
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // canBuy --> 1 yes ---> 0 no
        // when you buy you add -prices[i] to the answer wherease when you sell you add prices[i]
        int n = prices.size(), canBuy = 1;
        vector<int> ahead(2,0), curr(2,0);
        ahead[0]=0, ahead[1]=0;
        
        for(int index=n-1; index>=0; index--){
            for(int canBuy = 0; canBuy<=1; canBuy++){
                int profit = 0;
                if(canBuy==1){
                    profit = max(-prices[index]+ahead[0], 
                                 0+ahead[1]);
                }
                if(canBuy==0){
                    profit = max(prices[index]+ahead[1], 
                                 0+ahead[0]);
                }
                curr[canBuy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};