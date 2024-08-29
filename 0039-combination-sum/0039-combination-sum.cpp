class Solution {
private:
    void findCombination(int index, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>> &ans){
        if(index==candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            findCombination(index,target-candidates[index],candidates,ds,ans);
            ds.pop_back();
        }
        findCombination(index+1,target,candidates,ds,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates,ds,ans);
        return ans;
    }
};