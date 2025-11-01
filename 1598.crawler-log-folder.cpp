/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    int minOperations(const std::vector<std::string>& logs) {
        int res = 0;
        std::ranges::for_each(
            logs | std::views::filter([](const std::string& str) -> bool { return str != "./"; }),
            [&res](const char ch) -> void { res = ch == '.' ? std::max(res - 1, 0) : res + 1; },
            [](const std::string& operation) -> char { return operation[0]; });
        return res;
    }
};
// @lc code=end
