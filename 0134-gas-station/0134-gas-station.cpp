class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), gasSum = 0, costSum = 0;
        vector<int> difference;
        for(int i=0;i<n;i++){
            int x = gas[i]-cost[i];
            gasSum+=gas[i];
            costSum+=cost[i];
            difference.push_back(x);
        }
        if(gasSum<costSum){
            return -1;
        }
        int ans = 0, start = 0;
        for(int i=0;i<n-1;i++){
            ans+=difference[i];
            if(ans<0){
                ans=0;
                start = i+1;
            }
        }
        return start;
    }
};