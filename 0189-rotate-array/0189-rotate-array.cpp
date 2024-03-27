class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        /*
        to rotate 9 2 5 8 6 by k=2
        index val 0 1 2 3 4(n-1)
        goes to..     9 2 5 8 6(n+1) --- index + k gives this
        goes to.. 8 6 9 2 5 --- (index + k) % n gives this
        
        */
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums = temp;
    }
};