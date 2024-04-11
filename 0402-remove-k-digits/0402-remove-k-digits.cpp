class Solution {
public:
    string removeKdigits(string num, int k) {
        /* 
        The smallest integer can be found out if 
            the larger numbers from left are removed in case of decreasing order: 4 3 2 1
            the larger numbers from right are removed in case of increasing order: 1 2 3 4
        Monotonic Stack Approach: greedy way of thinking about the solution
        
        Example: 1432219
        keeping track of k and decrementing if we remove any num:
            add 1 to stack, add 4 (as 4>1), instead of adding 3(remove 4), then add 3(as 3>1),
            instead of adding 2(remove 3), then add 2 (as 2>1), add another 2, instead of 
            adding 1(remove 2), then add all (as k=0 now, we've been greedy enough): 1219  
        */
        stack<char> st;
        for(char c: num){
            while(k>0 && !st.empty() && st.top()>c){
                k--;
                st.pop();
            }
            st.push(c);
        }
        while(k>0 && !st.empty()){
                k--;
                st.pop();
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        } 
        reverse(res.begin(),res.end());
        int nonZeroIndex=0;
        while (nonZeroIndex < res.length() && res[nonZeroIndex] == '0') {
            nonZeroIndex++;
        }
        res = (nonZeroIndex == res.length()) ? "0" : res.substr(nonZeroIndex);
        return res;
    }
};