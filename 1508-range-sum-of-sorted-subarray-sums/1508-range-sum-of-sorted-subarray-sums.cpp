class Solution {
public:
    int m = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> res;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                res.push_back(sum);
            }
        }
        sort(res.begin(),res.end());
        int newSum = 0;
        for(int i=left-1; i<right;i++){
            newSum= (newSum + res[i])%m;
        }
        return newSum;
    }
};