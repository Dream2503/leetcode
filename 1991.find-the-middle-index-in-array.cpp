/*
 * @lc app=leetcode id=1991 lang=cpp
 *
 * [1991] Find the Middle Index in Array
 */

// @lc code=start
class Solution {
public:
    int findMiddleIndex(const std::vector<int>& nums) {
        const int size = nums.size();
        std::vector<int> left(size), right(size);
        left[0] = nums[0];
        right[size - 1] = nums[size - 1];

        for (int i = 1; i < size; i++) {
            left[i] = left[i - 1] + nums[i];
        }
        for (int i = size - 2; i >= 0; i--) {
            right[i] = right[i + 1] + nums[i];
        }
        for (int i = 0; i < size; i++) {
            if (left[i] == right[i]) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
