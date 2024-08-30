class Solution {
private:
    void helper(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int n, int target, int i){
        if(i==n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(nums[i]<=target){
            temp.push_back(nums[i]);
            helper(ans,temp,nums,n,target-nums[i],i);
            temp.pop_back();
        }
        helper(ans,temp,nums,n,target,i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        helper(ans,temp,candidates,n,target,0);
        return ans;
    }
};