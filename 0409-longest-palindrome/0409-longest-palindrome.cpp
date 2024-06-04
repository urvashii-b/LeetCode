class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int length = 0;
        for(char c:s){
            if(st.count(c)){
                st.erase(c);
                length+=2; // a....a 
            }else{
                st.insert(c);
            }
        }
        if(!st.empty()){
            length+=1; // odd - in the middle
        }
        return length;
    }
};