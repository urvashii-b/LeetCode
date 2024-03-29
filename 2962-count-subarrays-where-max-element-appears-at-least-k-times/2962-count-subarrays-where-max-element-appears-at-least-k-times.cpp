class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for(auto el: nums){
            maxi = max(maxi,el);
        }
        long long ans = 0, start = 0;
        for(int end = 0;end<nums.size();end++){
            if(nums[end]==maxi){
                k--;
            }
            while(!k){
                if(nums[start]==maxi){
                    k++;
                }
                start++;
            }
            ans+=start;
        }
        return ans;
    }
};