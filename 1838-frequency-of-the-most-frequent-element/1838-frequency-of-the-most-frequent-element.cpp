class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxi = 0, n = nums.size();
        long currentSum = 0;
        sort(nums.begin(),nums.end());
        for(int start = 0, end = 0; end<n;end++){
            currentSum+=nums[end];
            long x = nums[end];
            if(currentSum+k< x * (end-start+1)){
                currentSum-=nums[start];
                start++;
            }
            maxi = max(maxi,end-start+1);
        }
        return maxi;
    }
};