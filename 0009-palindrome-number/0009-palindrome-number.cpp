class Solution {
public:
    bool isPalindrome(int x) {
        // O(logn) time complexity
        if(x<0) return false;
        long long rev = 0;
        long long temp = x;
        while(temp){
            int digit = temp%10;
            rev = rev*10+digit;
            temp/=10;
        }
        // comparing reversed and original number to confirm whether palindrome or not
        return (rev==x);
    }
};