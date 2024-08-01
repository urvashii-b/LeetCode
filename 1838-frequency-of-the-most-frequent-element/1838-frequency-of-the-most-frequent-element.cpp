class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxi = 0, n = nums.size();
        long total = 0;
        sort(nums.begin(),nums.end());
        for(int start=0, end=0; end<n;end++){
            total += nums[end];
            long x = nums[end];
            if(total+k<x*(end-start+1)){
                total-=nums[start];
                start++;
            }
            maxi=max(maxi,end-start+1);
        }
        return maxi;
    }
};