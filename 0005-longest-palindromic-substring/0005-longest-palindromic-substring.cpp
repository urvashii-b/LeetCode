class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxlen=0;
        string res="";
        for(int i=0;i<n;i++){
            // odd
            int l = i;
            int r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                int lenn = r-l+1;
                if(lenn>maxlen){
                    maxlen = lenn;
                    res=s.substr(l,r-l+1);
                }
                l-=1;
                r+=1;
            }
            // even
            l = i, r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                int lenn = r-l+1;
                if(lenn>maxlen){
                    maxlen = lenn;
                    res=s.substr(l,r-l+1);
                }
                l-=1;
                r+=1;
            }
        }
        return res;
    }
};