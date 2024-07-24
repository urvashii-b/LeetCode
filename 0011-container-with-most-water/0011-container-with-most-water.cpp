class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        int maxarea = 0, n = height.size();
        for(int l=0;l<n;l++){
           for(int r=l+1;r<n;r++){
               int area = (r-l)*min(height[r],height[l]);   // width * min height
               maxarea = max(maxarea,area);
           } 
        }
        return maxarea;
        */
        int maxarea = 0, n = height.size();
        int l=0, r=n-1;
        while(l<r){
            int area = (r-l)*min(height[r],height[l]);
            maxarea = max(area,maxarea);
            if(height[l]<=height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxarea;
    }
};