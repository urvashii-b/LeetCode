class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (numRows <= 1 || numRows>=len) {
            return s;
        }
        string res = "";
        int dir = -1, row = 0; // -1: down, 1:up
        vector<char> a[numRows];
        for (auto c: s) {
            a[row].push_back(c);
            if(row==0 || row==numRows-1){
                dir*=-1;
            }
            row+=dir;
        }
        for(auto x: a){
            for(auto y:x){
                res+=y;
            }
        }
        return res;
    }
};