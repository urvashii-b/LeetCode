class Solution {
private:
    int solve(int currDay, vector<int> &dp, vector<int>& days, vector<int>& costs){
        int n = days.size();
        if(currDay>days[n-1]){
            return 0;
        }
        if(isTravelNeeded.find(currDay) == isTravelNeeded.end()){
            return solve(currDay+1, dp, days, costs);
        }
        if(dp[currDay]!=-1) return dp[currDay];
        
        int oneDay = costs[0] + solve(currDay+1, dp, days, costs);
        int sevenDay = costs[1] + solve(currDay+7, dp, days, costs);
        int thirtyDay = costs[2] + solve(currDay+30, dp, days, costs);
        
        return dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
    }
public:
    unordered_set<int> isTravelNeeded;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int lastDay = days[n-1];
        vector<int> dp(lastDay+1, -1);
        
        for(int& day: days){
            isTravelNeeded.insert(day);
        }
        
        return solve(1, dp, days, costs);
    }
};