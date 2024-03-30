class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        1. MID ELE IN SORTED ARRAY
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return nums[n/2];
        
        2.HASHMAP
        */
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        n=n/2;
        for(auto it:mpp){
            if(it.second>n){
                return it.first;
            }
        }
        return -1;
    }
};