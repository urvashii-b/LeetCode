class Solution {
public:
    bool checkString(string s) {
        /*
        CHECK SORTED
        return is_sorted(s.begin(),s.end());
        
        LOOP
        int n = s.size();
        for(int i=0;i<n-1;i++){
            if(s[i+1]<s[i]){
                return false;
            }
        }
        return true;
        */
        
        return s.find("ba")==string::npos;
    }
};