class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1){
            return 0; // 0 in the 1st row
        }
        int length = pow(2,n-1);
        int mid = length/2;
        if(k<=mid){
            return kthGrammar(n-1,k); // prev row's same kth grammar
        }else{
            return !kthGrammar(n-1,k-mid); // out of bounds for the previous one so flip the result
        }
    }
};
/*
see the pattern between current row and previous ones
0
0 1
0 1 1 0
0 1 1 0 1 0 0 1
        . . . .---> flipped 0 1 1 0
*/