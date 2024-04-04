class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        1. BRUTE - O(n^2) - NESTED FOR LOOPS
        
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
        
        2. BETTER -  O(2n) - HASHING
        
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
        
        3. OPTIMAL1 - O(n) - SUM
        
        int n = nums.size();
        int Tsum = (n*(n+1))/2;
        return  Tsum - accumulate(nums.begin(),nums.end(),0);
        
        4.a. OPTIMAL2 - O(2n) - XOR {two for loops}
        int n = nums.size();
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = ans^i;
        }
        for(int i=0;i<=n-1;i++){
            ans = ans^nums[i];
        }
        return ans;
        
        4.b. OPTIMAL2 - O(n) - XOR {one for loop}
        */
        int n = nums.size(); 
        int xor1 = 0, xor2 = 0;
        for(int i=0;i<=n-1;i++){
            xor1 = xor1^nums[i];
            xor2 = xor2^i;
        }
        xor2 = xor2^n;
        return xor1^xor2;
    }
};