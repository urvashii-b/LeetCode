class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxIndex = nums[0];
        for(int i=1;i<n;i++){
            if(i>maxIndex){
                return false;
            }
            maxIndex = max(maxIndex, i+nums[i]);
        }
        return true;
    }
};