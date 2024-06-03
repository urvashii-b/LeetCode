class Solution {
public:
    int minimumChairs(string s) {
        int n = s.length(), curr = 0, maxi = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='E'){
                curr++;
            }else if(s[i]=='L'){
                curr--;
            }
            maxi = max(curr,maxi);
        }
        return maxi;
    }
};