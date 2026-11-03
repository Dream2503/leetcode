/*
 * @lc app=leetcode id=2138 lang=cpp
 *
 * [2138] Divide a String Into Groups of Size k
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> divideString(const std::string& s, const int k, const char fill) {
        return s | std::views::chunk(k) | std::views::transform([k, fill](const auto& chunk) -> std::string {
                   std::string str(chunk.begin(), chunk.end());
                   str.resize(k, fill);
                   return str;
               }) |
            std::ranges::to<std::vector<std::string>>();
    }
};
// @lc code=end
