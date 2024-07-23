class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), i=0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
        while(lastJumpedPos<n-1){
            maxReachable = max(maxReachable, i + nums[i]);
            if(i==lastJumpedPos){
                jumps++;
                lastJumpedPos = maxReachable;
            }
            i++; 
        }
        return jumps;
    }
};