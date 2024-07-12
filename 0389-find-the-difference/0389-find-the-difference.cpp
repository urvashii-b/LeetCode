class Solution {
public:
    char findTheDifference(string s, string t) {   
        /*
        
        HASHMAP
        unordered_map<char,int> mpp;
        for(char &c: t){
            mpp[c]++;
        }
        for(char &x: s){
            mpp[x]--;
        }
        for(auto it: mpp){
            if(it.second>0){
                return it.first;
            }
        }
        return t[0]; // will never reach here
        
        
        SUM DIFFERENCE
        int sum = 0;
        for(char &c:t){
            sum+=c;
        }
        for(char &c:s){
            sum-=c;
        }
        return (char)sum;
        
        
        CHECK
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                return t[i];
            }
        }
        return t[n];
        
        
        XOR
        */
        int XOR = 0;
        for (char &ch: t)
            XOR ^= ch;
        
        for (char &ch: s)
            XOR ^=ch;
        
        return (char)XOR;
    }
};