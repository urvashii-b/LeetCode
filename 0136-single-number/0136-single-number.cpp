class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        1. BRUTE FORCE - O(N^2)
        */
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sel = nums[i];
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[j]==sel){
                    cnt++;
                }
            }
            if(cnt==1){
                return sel;
            }
        }
        return -1;
    }
};