/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */

// @lc code=start
class Solution {
public:
    int lengthLongestPath(const std::string& input) {
        int res = 0, total = 0;
        std::stack<std::string> stack;

        for (auto&& str : input | std::views::split('\n')) {
            const int tabs = std::ranges::count(str, '\t');
            const auto name = str | std::views::drop(tabs) | std::ranges::to<std::string>();

            while (stack.size() > tabs) {
                total -= stack.top().size();
                stack.pop();
            }
            if (std::ranges::contains(name, '.')) {
                res = std::max(res, static_cast<int>(total + stack.size() + name.size()));
            } else {
                stack.push(name);
                total += name.size();
            }
        }
        return res;
    }
};
// @lc code=end
