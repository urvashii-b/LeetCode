class Solution {
public:
    char findTheDifference(string s, string t) {   
        /*
        n = t.length() and m = s.length()
        1. hashmap - extra o(n) space, linear time
        unordered_map<char,int> mpp;
        for(char &c: t){
            mpp[c]++;
        }
        for(char &c: s){
            mpp[c]--;
        }
        for(auto& it: mpp){
            if(it.second>0){
                return it.first;
            }
        }
        return t[0]; // never reaches here
        
        2. sum difference - linear time, constant space
        int sum = 0;
        for(char &c: t){
            sum+=c;
        }
        for(char &c: s){
            sum-=c;
        }
        return (char)sum;
        
        3. sorting
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]!=t[i]){
                return t[i];
            }
        }
        return t[n];
        
        4. xor - linear time, constant space
        */
        int XOR = 0;
        for(char& c:s){
            XOR^=c;
        }
        for(char& c:t){
            XOR^=c;
        }
        return (char)XOR;
    }
};