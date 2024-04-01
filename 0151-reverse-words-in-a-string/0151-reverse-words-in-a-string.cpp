class Solution {
public:
    string reverseWords(string s) {
        /*
        BRUTE
        */
        string str = "";
        stack<string> st;
        
        // Skip leading spaces
        int start = 0;
        while (start < s.length() && s[start] == ' ') {
            start++;
        }

        // Extract words and push onto the stack
        for (int i = start; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (str != "") {
                    st.push(str);
                    str = "";
                }
            } else {
                str += s[i];
            }
        }

        // Push the last word if not empty
        if (str != "") {
            st.push(str);
        }

        // Reconstruct the string
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += " ";
            }
        }

        return ans;
    }
};