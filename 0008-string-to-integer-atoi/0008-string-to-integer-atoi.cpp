class Solution {
public:
    int myAtoi(string s) {
        int res=0, n=s.size(), ind = 0;
        if(n==0) return 0;
        while(ind<n && s[ind]==' '){    // whitespaces
            ind++;
        }
        bool neg = false;   // sign
        if(ind<n){
            if(s[ind]=='-'){
                neg = true;
                ind++;
            }else if(s[ind]=='+'){
                ind++;
            }
        }
        while(ind<n && isdigit(s[ind])){
            int digit = s[ind]-'0';
            if(res>(INT_MAX/10) || (res==(INT_MAX/10) && digit>7)){
                return neg? INT_MIN: INT_MAX;
            }
            res= res*10+digit;
            ind++;
        }
        return neg? -res:res;
    }
};