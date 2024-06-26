class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                cnt++;
            }
        }
        if(cnt>=2){
            return true;
        }
        return false;
    }
};