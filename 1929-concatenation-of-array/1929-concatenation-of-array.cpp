class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        /*
        APPROACH 1 - TWO FOR LOOPS
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }
        return ans;
        
        APPROACH 2 - ONE FOR LOOP
        int n = nums.size();
        vector<int> ans(2*n);
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
            ans[i+n]=nums[i];
        }
        return ans;
        */
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};