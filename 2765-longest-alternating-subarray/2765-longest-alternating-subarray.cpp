class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_len = -1;  
        int current_len = 1;  

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] == nums[i] + 1) {
                
                current_len = 2; 
                for (int j = i + 1; j < n - 1; ++j) {
                    if ((j - i) % 2 == 1 && nums[j + 1] == nums[j] - 1) {
                        current_len++;
                    } else if ((j - i) % 2 == 0 && nums[j + 1] == nums[j] + 1) {
                        current_len++;
                    } else {
                        break;
                    }
                }
                max_len = max(max_len, current_len);
            }
        }
        
        return max_len;
    }
};