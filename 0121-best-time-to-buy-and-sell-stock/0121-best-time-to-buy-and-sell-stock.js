/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let maxP = 0;
    let n = prices.length;
    let l = 0, r = 1;
    while(r<n){
        if(prices[l]<prices[r]){
            let profit = prices[r]-prices[l];
            maxP = Math.max(maxP,profit);
        }else{
            l=r;
        }
        r++;
    }
    return maxP;
};