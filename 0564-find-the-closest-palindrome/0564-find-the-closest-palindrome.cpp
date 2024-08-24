class Solution {
private:
    long halfToPalindrome(long left, bool even){
        long res = left;
        if(!even) left = left/10;
        while(left>0){
            res=res*10+left%10;
            left/=10;
        }
        return res;
    }
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        int mid = len%2==0? len/2-1:len/2;
        long firstHalf = stol(n.substr(0,mid+1));
        vector<long> possibilities; // n = 12345
        possibilities.push_back(halfToPalindrome(firstHalf,len%2==0));  // 12321
        possibilities.push_back(halfToPalindrome(firstHalf+1,len%2==0));    // 12221
        possibilities.push_back(halfToPalindrome(firstHalf-1,len%2==0));    // 12421
        possibilities.push_back((long)pow(10,len-1)-1); // 9999
        possibilities.push_back((long)pow(10,len)+1);   // 100001
        long diff = LONG_MAX, res = 0, n1 = stol(n);
        for(auto p: possibilities){
            if(p==n1) continue;
            if(abs(p-n1)<diff){
                diff = abs(p-n1);
                res=p;
            }else if(abs(p-n1)==diff){
                res=min(res,p);
            }
        }
        return to_string(res);
    }
};