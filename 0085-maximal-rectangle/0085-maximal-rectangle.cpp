class Solution {
private:
    int maximumArea(vector<int>& heights){
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) left[i]=0;
            else left[i]=st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) right[i]=n-1;
            else right[i]=st.top()-1;
            st.push(i);
        }
        
        int maxArea = 0;
        for(int i=0; i<n; i++){
            maxArea = max(maxArea, heights[i]*(right[i]-left[i]+1));
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxArea = 0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            int area = maximumArea(height);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};