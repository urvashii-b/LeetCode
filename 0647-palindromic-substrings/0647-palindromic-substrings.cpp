class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.size();
        for(int i=0;i<n;i++){
            int l = i;
            int r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                res++;
                l-=1;
                r+=1;
            }
            l = i, r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                res++;
                l-=1;
                r+=1;
            }
        }
        return res;
    }
};