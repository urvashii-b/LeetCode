class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        char maxChar = ' ';
        for(int i=2; i<n; i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                maxChar = max(maxChar,num[i]);
            }
        }
        if(maxChar==' ') return "";
        return string(3,maxChar);
    }
};