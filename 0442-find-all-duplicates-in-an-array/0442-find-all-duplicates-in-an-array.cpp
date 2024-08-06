class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<int> ans;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(auto it: freq){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};