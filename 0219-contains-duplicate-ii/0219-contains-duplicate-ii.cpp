class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window; // Sliding window approach
    int n = nums.size();
    int l = 0;
    for (int r = 0; r < n; ++r) {
        if (r - l > k) {
            window.erase(nums[l]);
            l += 1;
        }
        if (window.count(nums[r])) {
            return true;
        }
        window.insert(nums[r]);
    }
    return false;
}

};