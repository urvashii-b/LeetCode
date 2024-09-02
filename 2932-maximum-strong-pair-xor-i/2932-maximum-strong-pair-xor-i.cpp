class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int maxXor = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int x = nums[i];
                int y = nums[j];
                
                if(abs(x-y)<=min(x,y)){
                    maxXor = max(maxXor, x^y);
                }
            }
        }
        return maxXor;
    }
};