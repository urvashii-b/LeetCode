class Solution {
private:
    void recurPermute(int freq[], vector<vector<int>> &ans, vector<int> &ds, vector<int>& nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(nums[i]);
                recurPermute(freq, ans, ds, nums);
                ds.pop_back();
                freq[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for(int i=0;i<n;i++){
            freq[i]=0;
        }
        recurPermute(freq, ans, ds, nums);
        return ans;
    }
};