class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        1. BRUTE - O(n^2)
        
        for(int i=1;i<=nums.size();i++){
            int flag = 0;
            for(int j = 0;j<nums.size()-1;j++){
                if(nums[j]==i){
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                return i;
            }
        }
        return -1;
        
        2. BETTER - O(2n)
        
        3. OPTIMAL
        
        */
        int hash[10001]={0};
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<=nums.size();i++){
            if(hash[i]==0){
                return i;
            }
        }
        return -1;
    }
};