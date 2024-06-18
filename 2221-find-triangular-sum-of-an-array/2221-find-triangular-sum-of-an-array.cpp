class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int ans=0;int k=nums.size();
        while(k!=1){
            for(int i=0;i<k-1;i++)
                nums[i]= (nums[i]+nums[i+1])%10;
            k--;
        }
        return nums[0];
    }
};