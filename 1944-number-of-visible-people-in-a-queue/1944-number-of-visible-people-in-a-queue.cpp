class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int cnt = 0;
            while(!st.empty() && st.top()<heights[i]){
                cnt++;
                st.pop();
            }
            ans[i]= i==n-1? 0: max(1,cnt+(!st.empty()));
            st.push(heights[i]);
        }
        return ans;
    }
};