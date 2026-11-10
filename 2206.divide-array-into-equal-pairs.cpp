/*
 * @lc app=leetcode id=2206 lang=cpp
 *
 * [2206] Divide Array Into Equal Pairs
 */

// @lc code=start
class Solution {
public:
    bool divideArray(const std::vector<int>& nums) {
        return std::ranges::count_if(nums | std::views::transform([&nums](const int num) -> int { return std::ranges::count(nums, num); }),
                                     [](const int value) -> bool { return value % 2 == 0; }) == nums.size();
    }
};
// @lc code=end
