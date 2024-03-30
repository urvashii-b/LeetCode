class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        int i =0;
        // int ele= nums[0];
        for(auto ele : nums)
        {
            if(i==0 || i==1 || nums[i-2] != ele)
            {
                nums[i] = ele;
                i++;
            }
        }
        return i ;
        */
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};