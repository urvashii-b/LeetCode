class Solution {
public:
    int myAtoi(string s) {
        int ans = 0, n = s.size(), index = 0;
        if(n==0) return 0;
        // ignore whitspaces
        while(index<n && s[index]==' '){
            index++;
        }
        bool neg = false;
        // positive / negative number
        if(index<n){
            if(s[index]=='-'){
                neg = true;
                index++;
            } else if(s[index]=='+'){
                index++;
            }
        }
        while(index<n && isdigit(s[index])){
            int digit = s[index]-'0';
            // limits crossed
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && digit>7)){
                return neg? INT_MIN : INT_MAX;
            }
            ans = ans*10 + digit;
            index++;
        }
        return neg? -ans :ans;
    }
};