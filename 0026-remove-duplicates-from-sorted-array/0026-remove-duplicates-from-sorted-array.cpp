class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){ // keep checking adjacent pairs
                nums[i+1]=nums[j]; // add if it is unique
                i++;
            }
        }
        return (i+1);
    }
};