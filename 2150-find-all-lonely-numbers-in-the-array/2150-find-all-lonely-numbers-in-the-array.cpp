class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(mpp.find(x+1)==mpp.end() && mpp.find(x-1)==mpp.end() && mpp[x]==1){
                ans.push_back(x);
            }
        }
        return ans;
    }
};