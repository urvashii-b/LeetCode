class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res = "";
        int inc = 2 * (numRows - 1);
        for (int r = 0; r < numRows; r++) {
            for (int i = r; i < s.length(); i += inc) {
                res += s[i];
                if (r > 0 && r < numRows - 1 && i + inc - 2 * r < s.length()) {
                    res += s[i + inc - 2 * r];
                }
            }
        }
        return res;
    }
};