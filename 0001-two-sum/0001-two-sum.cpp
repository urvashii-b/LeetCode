class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* 1. Brute Force
       
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
        
        2. Better using hashtable - unordered_map (two pass)
        unordered_map<int,int> freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int complement = target - nums[i];
            if(freq.count(complement) && freq[complement]!=i){
                return {i,freq[complement]};
            }
        }
        return {};
        
        3. Better using hashtable - unordered_map (one pass)
        */
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            int complement = target - nums[i];
            if(freq.count(complement)){
                return {freq[complement],i};
            }
            freq[nums[i]]=i;
        }
        return {};
    }
};