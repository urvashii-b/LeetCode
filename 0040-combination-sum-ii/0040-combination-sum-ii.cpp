class Solution {
private:
    void helper(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int n, int target, int index){
        if(target==0){
            ans.push_back(temp);
        return;
        }
        for(int i=index; i<n; i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            temp.push_back(nums[i]);
            helper(ans,temp,nums,n,target-nums[i],i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        helper(ans,temp,candidates,n,target,0);
        return ans;
    }
};