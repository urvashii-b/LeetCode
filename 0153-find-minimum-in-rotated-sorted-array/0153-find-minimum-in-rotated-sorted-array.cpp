class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i+1]<nums[i]){
                return nums[i+1];
            }
        }
        return 0;
        */
        int n = nums.size(), ans = INT_MAX;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid]){
                ans = min(ans,nums[low]);
                low = mid+1;
            }else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};