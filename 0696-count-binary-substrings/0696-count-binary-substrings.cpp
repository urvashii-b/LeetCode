class Solution {
public:
    int countBinarySubstrings(string s) {
        int sum = 0, prev = 0, cur = 1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cur++;
            }else{
                sum+=min(prev,cur);
                prev = cur;
                cur = 1;
            }
        }
        sum+=min(prev,cur);
        return sum;
    }
};