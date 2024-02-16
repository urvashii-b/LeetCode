class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        /* 1. brute force
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    return true;
                }
            }
        }
        return false;
        
        2. better approach
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i++){
                if(nums[i]==nums[i+1]){
                    return true;
                }
        }
        return false;
        
        3. set approach
        4. optimal but contains tradeoff
        */
        return nums.size() > set<int>(nums.begin(),nums.end()).size();
        
    }
};