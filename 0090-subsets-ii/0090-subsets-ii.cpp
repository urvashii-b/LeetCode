class Solution {
private:
    void helper(vector<vector<int>> &ans, vector<int> &temp, int n, int start, vector<int> &arr){
        ans.push_back(temp);
        for(int i=start; i<arr.size(); i++){
            if(i > start && arr[i]==arr[i-1]) continue;
            temp.push_back(arr[i]);
            helper(ans,temp,n,i+1,arr);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        helper(ans,temp,n,0, nums);
        return ans;
    }
};