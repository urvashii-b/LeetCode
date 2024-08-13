class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        int n = nums.size();
        int mini = INT_MAX;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target){
                    return target;
                }else if(sum>target){
                    k--;
                }else{
                    j++;
                }
                int diff = abs(sum-target);
                if(mini>diff){
                    mini = diff;
                    ans = sum;
                }

            }
        }
        return ans;
    }
};