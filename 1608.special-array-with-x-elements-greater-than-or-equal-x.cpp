/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        const int size = nums.size();
        std::ranges::sort(nums);

        for (int i = size - 1; i >= 0; --i) {
            if (nums[i] >= size - i && (i == 0 || nums[i - 1] < size - i)) {
                return size - i;
            }
        }
        return -1;
    }
};
// @lc code=end
