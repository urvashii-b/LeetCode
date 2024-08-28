#include <vector>
class Solution {
private:
    int findLeft(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                index = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return index;
    }

    int findRight(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                index = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);

        if (left <= right) {
            return {left, right};
        } else {
            return {-1, -1};
        }
    }
};