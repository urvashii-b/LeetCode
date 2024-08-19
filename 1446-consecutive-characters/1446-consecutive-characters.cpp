class Solution {
public:
    int maxPower(string s) {
        int n = s.length(), cnt = 1, maxi = 0;
        if(n==1) return 1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
                
            }else{
                cnt = 1;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};