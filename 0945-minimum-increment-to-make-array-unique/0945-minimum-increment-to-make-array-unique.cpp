class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int increments = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]){
                increments+= 1 + nums[i-1] - nums[i];
                nums[i] = nums[i-1]+1;
            }
        }
        return increments;
    }
};