class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxi = 0;
        int n = nums.size();
        long currentSum = 0;
        
        sort(nums.begin(), nums.end());  // Sort the array to use the sliding window technique
        
        for (int start = 0, end = 0; end < n; end++) {
            currentSum += nums[end];
            long x = nums[end];
            
            // Check if we can make all elements from start to end equal to nums[end] with at most k increments
            if (currentSum + k < x * (end - start + 1)) {
                // If not, shrink the window from the left
                currentSum -= nums[start];
                start++;
            }
            
            // Update the maximum frequency
            maxi = max(maxi, end - start + 1);
        }
        
        return maxi;
    }
};