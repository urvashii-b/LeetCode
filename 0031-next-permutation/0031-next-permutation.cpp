class Solution {
    /*
private:
    void permutations(int index, vector<vector<int>>& ans, vector<int>& nums){
        int n = nums.size()
        if(index==n){
            ans.push_back(nums)
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            permutations(index+1,ans,nums);
            swap(nums[i],nums[index]); // backtracking
        }
    }
    */
public:
    void nextPermutation(vector<int>& nums) {
        /* 
        STL
        next_permutation(nums.begin(),nums.end()); 
        
        
        ALL PERMUTATIONS
        vector<vector<int>> ans;
        permutations(0,ans,nums);
        sort(ans.begin(),ans.end());
        auto it = find(ans.begin(),ans.end(),nums);
        if(it!=ans.end() && next(it)!=ans.end()){
            nums = *next(it);
        }else{
            nums = ans.front();
        }
        
        
        OPTIMAL
        */
        int n = nums.size(), index = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
        }else{
            for(int i=n-1;i>=index;i--){
                if(nums[i]>nums[index]){
                    swap(nums[i],nums[index]);
                    break;
                }
            }
            reverse(nums.begin()+index+1,nums.end());
        }
    }
};