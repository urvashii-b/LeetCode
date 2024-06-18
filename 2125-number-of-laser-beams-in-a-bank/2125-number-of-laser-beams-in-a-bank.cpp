class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0;
        
        for(string s: bank){
            int cnt = 0;
            for(char c: s){
                if(c=='1'){
                    cnt++;
                }
            }
            if(cnt!=0){
                res += (prev*cnt);
                prev = cnt;
            }
        }
        return res;
    }
};