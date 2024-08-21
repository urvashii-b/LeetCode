class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), gasSum = 0, costSum = 0;
        vector<int> diff;
        for(int i=0;i<n;i++){
            gasSum+=gas[i];
            costSum+=cost[i];
            int difference = gas[i]-cost[i];
            diff.push_back(difference);
        }
        if(gasSum<costSum){
            return -1;
        }
        int ans = 0, start = 0;
        for(int i=0;i<n;i++){
            ans+=diff[i];
            if(ans<0){
                ans = 0;
                start = i+1;
            }
        }
        return start;
    }
};