class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        for(int i=1;i<n;i++){
            if((nums[i-1]&1)^(nums[i]&1)==0){ // 0-0 or 1-1 gives 0 (bitwise or)
                return false;
            }
        }
        return true;
    }
};