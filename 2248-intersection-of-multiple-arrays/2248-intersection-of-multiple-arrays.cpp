class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> freq;
        for(vector<int> row: nums){
            for(int num: row){
                freq[num]++;
                if(freq[num]==n){
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};