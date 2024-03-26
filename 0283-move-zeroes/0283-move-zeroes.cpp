class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        1. BRUTE FORCE = O(N) + O(X) + O(N-X) ~ O(2*N)
        
        // store all the non zero elements in a temporary array 
        vector<int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        int nz = temp.size();
        // update the non zero elements in the original array
        for(int i=0;i<nz;i++){
            nums[i]=temp[i];
        }
        // add zeroes in the leftover places
        for(int i=nz;i<n;i++){
            nums[i]=0;
        } 
        
        2. OPTIMAL = O(N) as we are traversing the array once
        
        */
        int j = -1;
        // find the first '0' element and point j to that location
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        // if no '0' found, then do nothing
        if(j==-1){
            return;
        }
        int n = nums.size();
        // swap if any non zero element is encountered
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }    
    }
};