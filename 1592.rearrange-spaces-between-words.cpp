/*
 * @lc app=leetcode id=1592 lang=cpp
 *
 * [1592] Rearrange Spaces Between Words
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    std::string reorderSpaces(const std::string& text) {
        int spaces = std::ranges::count(text, ' ');
        auto range = text | std::views::split(' ') | std::views::filter([](const auto& ch) -> bool { return !ch.empty(); });
        const int space = spaces / std::max(std::ranges::count_if(range, [](const auto& ch) -> bool { return !ch.empty(); }) - 1, 1l);
        std::string res;
        res.reserve(text.length());

        for (const auto& word : range) {
            res.append(word.begin(), word.end()).append(std::min(space, spaces), ' ');
            spaces -= space;
        }
        return spaces > 0 ? res.append(spaces, ' ') : res;
    }
};
// @lc code=end
