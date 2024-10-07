class Solution {
public:
    int minLength(string s) {
        /*
        O(n^2)
        while(s.find("AB")!=-1 || s.find("CD")!=-1){
            if(s.find("AB")!=-1){
                s.erase(s.find("AB"),2);
            }else if(s.find("CD")!=-1){
                s.erase(s.find("CD"),2);
            }
        }
        return s.length();
        
        O(n)
        */
        stack<char> st;
        for(char c: s){
            char curr = c;
            if(st.empty()){
                st.push(curr);
                continue;
            }
            if(curr=='B' && st.top()=='A'){
                st.pop();
            }else if(curr=='D' && st.top()=='C'){
                st.pop();
            }else{
                st.push(curr);
            }
        }
        return st.size();
    }
};