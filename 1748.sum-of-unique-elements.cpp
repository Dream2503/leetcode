/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */

// @lc code=start
class Solution {
public:
    int sumOfUnique(std::vector<int>& nums) {
        const int size = nums.size();
        bool increment = false;
        int i = 0, res = 0;
        std::ranges::sort(nums);

        while (i < size) {
            do {
                increment = false;

                while (i < size - 1 && nums[i + 1] == nums[i]) {
                    increment = true;
                    i++;
                }
                i += increment;
            } while (increment);
            if (i < size) {
                res += nums[i];
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
