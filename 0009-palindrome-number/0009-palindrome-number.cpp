class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long rev = 0;
        long long temp = x;
        while(temp){
            int digit = temp%10;
            rev = rev*10+digit;
            temp/=10;
        }
        return (rev==x);
    }
};