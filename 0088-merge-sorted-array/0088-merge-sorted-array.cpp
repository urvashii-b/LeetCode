class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        1. STL: 
        for(int j=0,i=m;j<n;j++){
            nums1[i]=nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
        
        2. Basic Approach
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            ans.push_back(nums1[i++]);
        }
        while(j<n){
            ans.push_back(nums2[j++]);
        }
        for(int i=0;i<ans.size();i++){
            nums1[i]=ans[i];
        }
        
        3. Without extra space - approach 1
        */
        int left = m-1, right = n-1, end = m+n-1;
        while(left>=0 && right>=0){
            if(nums1[left]>nums2[right]){
                nums1[end]=nums1[left];
                left--;
            }else{
                nums1[end]=nums2[right];
                right--;
            }
            end--;
        }
        while(right>=0){
            nums1[end]=nums2[right];
            end--;
            right--;
        }
    }
};