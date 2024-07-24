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
        int mini = INT_MAX, n = nums.size();
        int l=0, r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[l]<=nums[mid]){ // left portion (right to be checked)
                mini = min(mini, nums[l]);
                l=mid+1;
            }else{  // mid portion (left to be checked)
                mini = min(mini, nums[mid]);
                r=mid-1;
            }
        }
        return mini;
    }
};