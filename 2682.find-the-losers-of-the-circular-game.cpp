/*
 * @lc app=leetcode id=2682 lang=cpp
 *
 * [2682] Find the Losers of the Circular Game
 */

// @lc code=start
class Solution {
public:
    std::vector<int> circularGameLosers(const int n, const int k) {
        std::vector<uint8_t> hash(n, true);
        int current = 0, i = 1;

        while (hash[current]) {
            hash[current] = false;
            current = (current + i++ * k) % n;
        }
        return hash | std::views::enumerate |
            std::views::filter([](const std::tuple<int, uint8_t>& element) -> bool { return std::get<1>(element); }) | std::views::elements<0> |
            std::views::transform([](const int num) -> int { return num + 1; }) | std::ranges::to<std::vector<int>>();
    }
};
// @lc code=end
