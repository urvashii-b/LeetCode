class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        1. BRUTE FORCE
        int j = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=nums[i];
                break;
            }
        }
        if(j==-1){
            return;
        }
        
        */
        vector<int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        int nz = temp.size();
        for(int i=0;i<nz;i++){
            nums[i]=temp[i];
        }
        for(int i=nz;i<n;i++){
            nums[i]=0;
        }   
    }
};