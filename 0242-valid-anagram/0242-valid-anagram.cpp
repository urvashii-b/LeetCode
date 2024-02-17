class Solution {
public:
    bool isAnagram(string s, string t) {
        
        /* 1. Sorting
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){return true;}
        return false;
        
        
        2. Better approach using hashmap
        unordered_map<char,int> mpp;
        for(auto i:s){
            mpp[i]++;
        }
        
        for(auto i:t){
            mpp[i]--;
        }
        
        for(auto i:mpp){
            if(i.second!=0){
                return false;
            }
        }
        return true;
        
        
        3. Better approach using hashset
        */
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};