class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int charIndex = 0;
        long maxCharIndex = strs[0].length();
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].length() > maxCharIndex) {
                maxCharIndex = strs[i].length();
            }
        }
        while (charIndex < maxCharIndex) {
            char prevChar = strs[0][charIndex];
            for (int i = 1; i < strs.size(); ++i) {
                if (prevChar == strs[i][charIndex]) {
                    continue;
                }
                return res.substr(0, charIndex);
            }
            ++charIndex;
            res += prevChar;
        }
        return res.substr(0, charIndex);
    }
};