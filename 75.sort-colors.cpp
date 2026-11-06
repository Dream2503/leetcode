/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        const int size = nums.size();

        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;

            for (int j = 0; j < size - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
};
// @lc code=end
