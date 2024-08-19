class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size(), cnt1 = 0, cnt0 = 0, maxcnt1 = 0, maxcnt0 = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt1++;
                maxcnt1=max(maxcnt1,cnt1);
                cnt0=0;
            }else{
                cnt1=0;
                cnt0++;
                maxcnt0=max(maxcnt0,cnt0);
            }
        }
        return maxcnt1>maxcnt0;
    }
};