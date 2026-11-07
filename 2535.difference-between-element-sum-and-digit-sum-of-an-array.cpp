/*
 * @lc app=leetcode id=2535 lang=cpp
 *
 * [2535] Difference Between Element Sum and Digit Sum of an Array
 */

// @lc code=start
class Solution {
public:
    int differenceOfSum(const std::vector<int>& nums) {
        return std::abs(std::ranges::fold_left(nums, 0, std::plus()) - std::ranges::fold_left(nums, 0, [](int lhs, int rhs) -> int {
                            while (rhs) {
                                lhs += rhs % 10;
                                rhs /= 10;
                            }
                            return lhs;
                        }));
    }
};
// @lc code=end
