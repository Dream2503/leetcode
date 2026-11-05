/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(const std::vector<int>& piles, const int h) {
        return *std::ranges::lower_bound(std::views::iota(1, std::ranges::max(piles) + 1), h, [&piles](const int speed, const int hours) -> bool {
            return std::ranges::fold_left(piles, 0, [&speed](const int lhs, const double rhs) -> double { return lhs + std::ceil(rhs / speed); }) >
                hours;
        });
    }
};
// @lc code=end
