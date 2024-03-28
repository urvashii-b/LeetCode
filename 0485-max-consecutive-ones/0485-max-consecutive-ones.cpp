class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // O(n)
        int n = nums.size(), cnt=0, maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                maxi = max(maxi,cnt);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;
    }
};