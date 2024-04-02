class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpST;
        unordered_map<char,char> mpTS;
        
        for(int i=0;i<s.size();i++){
            char charS = s[i];
            char charT = t[i];
            
            if(mpST.find(charS)!=mpST.end()){
                if(mpST[charS]!=charT){
                    return false;
                }
            }else{
                if(mpTS.find(charT)!=mpTS.end()){
                    return false;
                }
                
                mpST[charS]=charT;
                mpTS[charT]=charS;
            } 
        }
        return true;
    }
};