class Solution {
private:
    string build(string s){
        int c=0, n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='#') c=max(0,--c);
            else s[c++]=s[i];
        }
        return s.substr(0,c);
    }
public:
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
};