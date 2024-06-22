class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), zeroSum = 0, oneSum=0, maxii=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                zeroSum+=customers[i]; // for all '0' - not grumpy
            }
            if(i<minutes){
                oneSum+= grumpy[i]==1?customers[i]:0;
            }else{ // one more ele than window size then remove first ele
                oneSum+= (grumpy[i]==1?customers[i]:0)-(grumpy[i-minutes]==1?customers[i-minutes]:0);
            }
            maxii = max(oneSum, maxii);
        }
        int ans = zeroSum + maxii;
        return ans;
    }
};