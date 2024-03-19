class Solution {
public:
    int sum(int num1, int num2) {
        /* 
        1. BITWISE: 
        return (num2==0)? num1: sum(num1^num2,((unsigned int)(num1&num2))<<1);
        
        2. BASIC:
        */
        return num1+num2;
    }
};