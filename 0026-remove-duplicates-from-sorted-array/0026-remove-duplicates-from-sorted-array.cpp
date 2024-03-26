class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* 
        BRUTE FORCE = O(n*log(n))+O(n)
        
        // set data structure as it stores unique elements
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int k = st.size();
        int index = 0;
        // update original array with the non repeating elements present in set
        for (auto it: st){
            nums[index] = it;
            index++;
        }
        // size of set is the number of unique elements in the array
        return k;
        
        OPTIMAL = 
        */
        int i = 0;
        int n = nums.size();
        // iterate from j=1 to n and update using i if there is a unique element
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        // as it is 0-based indexing
        return (i+1); 
    }
};