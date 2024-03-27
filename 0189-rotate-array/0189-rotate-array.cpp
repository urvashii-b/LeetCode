class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        vector<int> temp(nums.size());
        
        to rotate 9 2 5 8 6 by k=2
        index val 0 1 2 3 4(n-1)
        goes to..     9 2 5 8 6(n+1) --- index + k gives this
        goes to.. 8 6 9 2 5 --- (index + k) % n gives this
        
        
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums = temp;
        
        2. OPTIMAL
        1 5 7 8 9 6 2 and k = 3
        7 5 1..2 6 9 8 to
        8 9 6 2 1 5 7
        */
        int n=nums.size();
        k = k % n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};