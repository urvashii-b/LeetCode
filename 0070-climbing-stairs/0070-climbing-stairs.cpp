class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int c;
        int a = 1, b = 1;
        for(int i=2;i<=n;i++){
            c = a+b;
            a = b;
            b= c;
        }
        return c;
    }
};