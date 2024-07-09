class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while(n){
            if((n&1)==1){
                ans++;
            }
            n=n>>1; // right shift to remove last digit
        }
        return ans;
    }
};