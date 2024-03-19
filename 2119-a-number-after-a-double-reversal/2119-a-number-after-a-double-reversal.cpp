class Solution {
public:
    bool isSameAfterReversals(int num) {
        int temp = num;
        int reversed1 = 0;
        while(temp!=0){
            int last = temp%10;
            reversed1= reversed1*10+last;
            temp/=10;
        }
        int rev=0;
        while(reversed1!=0){
            int last2 = reversed1%10;
            rev=rev*10+last2;
            reversed1/=10;
        }
        return (num==rev);
    }
};