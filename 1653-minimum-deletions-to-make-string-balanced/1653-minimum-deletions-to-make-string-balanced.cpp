class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> cnta(n,0);
        vector<int> cntb(n,0);
        int bcnt = 0;
        for(int i=0;i<n;i++){
            cntb[i]=bcnt;
            if(s[i]=='b') bcnt++;
        }
        int acnt = 0;
        for(int i=n-1;i>=0;i--){
            cnta[i]=acnt;
            if(s[i]=='a') acnt++;
        }
        int mini = n;
        for(int i=0;i<n;i++){
            mini = min(mini,cnta[i]+cntb[i]);
        }
        return mini;
    }
};