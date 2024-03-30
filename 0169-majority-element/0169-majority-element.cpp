class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        1. Middle element in sorted array
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return nums[n/2];
        
        2.Hashmap
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
        
        3. Moore Voting Algorithm
        if there is a majority element in an array, it will always remain in the lead, even           after encountering other elements.
        */
        int cnt = 0, candidate = 0;
        for(int i:nums){
            if(cnt==0){
                candidate = i;
            }
            if(i==candidate){
                cnt++;
            }else{
                cnt--;
            }
        }
        return candidate;
    }
};