class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, n = prices.size(), l=0, r=1;
        while(r<n){
            if(prices[l]<prices[r]){
                int profit = prices[r]-prices[l];
                maxP = max(maxP, profit);
            }else{
                l=r;
            }
            r++;
        }
        return maxP;
    }
};