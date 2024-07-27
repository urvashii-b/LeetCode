class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry = 0, i = a.size()-1, j = b.size()-1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i>=0){
                sum+=a[i--]-'0';
            }
            if(j>=0){
                sum+=b[j--]-'0';
            }
            carry = sum/2;
            sum=sum%2;
            ans=to_string(sum)+ans;
        }
        return ans;
    }
};