class Solution {
public:
    bool isAnagram(string s, string t) {
        
        /* 1. Sorting
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){return true;}
        return false;
        
        2. Better approach using hashmap
        */
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
        
    }
};