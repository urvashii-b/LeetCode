class Solution {
public:
    bool areNumbersAscending(string s) {
        int n =s.size(), ind=0;
        vector<int> digits;
        while(ind<n){
            if(isdigit(s[ind])){
                int num = 0;
                while(ind<n && isdigit(s[ind])){
                    num = num*10 + (s[ind]-'0');
                    ind++;
                }
                digits.push_back(num);
            }else{
                ind++;
            }
        }
        for(int i=1;i<digits.size();i++){
            if(digits[i]<=digits[i-1]){
                return false;
            }
        }
        return true;
    }
};