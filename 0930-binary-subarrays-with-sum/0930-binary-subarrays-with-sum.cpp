class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), cnt = 0, prefixSum = 0;
        map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int rem = prefixSum - goal;
            cnt+=mpp[rem];
            mpp[prefixSum]++;
        }
        return cnt;
    }
};