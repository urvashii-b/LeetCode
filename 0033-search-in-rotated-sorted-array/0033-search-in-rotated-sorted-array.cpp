class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
        */
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(target==nums[mid]) return mid;
            if(nums[low]<=nums[mid]){    // left sorted
                if(target>nums[mid] || nums[low]>target){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }else{      // right sorted
                if(target>nums[high] || target<nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }
        return -1;
    }
};