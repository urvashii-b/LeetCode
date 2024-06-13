class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump=nums[0],n=nums.size();
        for(int i=1;i<n;i++){
            if(maxjump>=i){
                maxjump = max(maxjump, i+nums[i]);
            }
        }
        return maxjump>=n-1;
    }
};