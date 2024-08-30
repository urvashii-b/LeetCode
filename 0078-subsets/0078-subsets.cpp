class Solution {
private:
    void helper(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int n, int start){
        ans.push_back(temp);
        for(int i=start; i<n; i++){
            temp.push_back(nums[i]);
            helper(ans,temp,nums,n,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        helper(ans,temp,nums,n,0);
        return ans;
    }
};