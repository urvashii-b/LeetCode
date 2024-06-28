class Solution {
private:
    int cnt(int l, int r, string &s){
        int res = 0, n = s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            res++;
            l-=1;
            r+=1;
        }
        return res;
    }
public:
    int countSubstrings(string s) {
        int res = 0, n = s.size();
        for(int i=0;i<n;i++){
            res+= cnt(i,i,s);
            res+= cnt(i,i+1,s);
        }
        return res;
    }
};