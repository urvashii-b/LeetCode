#include <bits/stdc++.h>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double prefix = 1, suffix = 1, maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix = 1;
            if(suffix==0) suffix = 1;
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            maxi = max(max(prefix,suffix),maxi);
        }
        return maxi;
    }
};